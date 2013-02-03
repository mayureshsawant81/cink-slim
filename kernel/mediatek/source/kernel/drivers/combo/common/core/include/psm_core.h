/*! \file
    \brief  Declaration of library functions

    Any definitions in this file will be shared among GLUE Layer and internal Driver Stack.
*/

/*******************************************************************************
* Copyright (c) 2009 MediaTek Inc.
*
* All rights reserved. Copying, compilation, modification, distribution
* or any other use whatsoever of this material is strictly prohibited
* except in accordance with a Software License Agreement with
* MediaTek Inc.
********************************************************************************
*/

/*******************************************************************************
* LEGAL DISCLAIMER
*
* BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND
* AGREES THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK
* SOFTWARE") RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE
* PROVIDED TO BUYER ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY
* DISCLAIMS ANY AND ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT
* LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
* PARTICULAR PURPOSE OR NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE
* ANY WARRANTY WHATSOEVER WITH RESPECT TO THE SOFTWARE OF ANY THIRD PARTY
* WHICH MAY BE USED BY, INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK
* SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY
* WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE
* FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S SPECIFICATION OR TO
* CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
* BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
* LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL
* BE, AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT
* ISSUE, OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY
* BUYER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
* THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
* WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT
* OF LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING
* THEREOF AND RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN
* FRANCISCO, CA, UNDER THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE
* (ICC).
********************************************************************************
*/


#ifndef _PSM_CORE_H
#define _PSM_CORE_H

#include "osal_typedef.h"
#include "osal.h"
#include "stp_wmt.h"

/*******************************************************************************
*                         C O M P I L E R   F L A G S
********************************************************************************
*/

/*******************************************************************************
*                                 M A C R O S
********************************************************************************
*/
#define PFX_PSM                         "[STP-PSM] "
#define STP_PSM_LOG_LOUD                 4
#define STP_PSM_LOG_DBG                  3
#define STP_PSM_LOG_INFO                 2
#define STP_PSM_LOG_WARN                 1
#define STP_PSM_LOG_ERR                  0

#define ASSERT(expr)
#define STP_PSM_FIFO_SIZE  0x2000//8kbytes
#define STP_PSM_TX_SIZE    0x800 //2kbytes

#define STP_PSM_OPERATION_FAIL    (-1)
#define STP_PSM_OPERATION_SUCCESS (0)

#define STP_PSM_PACKET_SIZE_MAX (2000)


#define PSM_HANDLING 127

#define STP_PSM_WMT_PS_TASK_HANDLING_TIME  30   //20 milli-seconds
#define STP_PSM_IDLE_TIME_SLEEP           5000   //temporary for stress testing
#define STP_PSM_WAIT_EVENT_TIMEOUT        6000

#define STP_PSM_WMT_EVENT_SLEEP_EN                    (0x1UL << 0)
#define STP_PSM_WMT_EVENT_WAKEUP_EN                   (0x1UL << 1)
#define STP_PSM_BLOCK_DATA_EN                         (0x1UL << 2)
#define STP_PSM_WMT_EVENT_DISABLE_MONITOR             (0x1UL << 3)
#define STP_PSM_WMT_EVENT_ROLL_BACK_EN                (0x1UL << 4)
#define STP_PSM_RESET_EN                              (0x1UL << 5)
#define STP_PSM_WMT_EVENT_HOST_WAKEUP_EN                    (0x1UL << 6)
#define STP_PSM_WMT_EVENT_DISABLE_MONITOR_TX_HIGH_DENSITY   (0x1UL << 7) 
#define STP_PSM_WMT_EVENT_DISABLE_MONITOR_RX_HIGH_DENSITY   (0x1UL << 8)

/* OP command ring buffer : must be power of 2 */
#define STP_OP_BUF_SIZE (16)

#define PSM_THREAD_NAME "mtk_stp_psm"

/*******************************************************************************
*                    E X T E R N A L   R E F E R E N C E S
********************************************************************************
*/



/*******************************************************************************
*                              C O N S T A N T S
********************************************************************************
*/

/*******************************************************************************
*                             D A T A   T Y P E S
********************************************************************************
*/
typedef enum {
    ACT = 0,
    ACT_INACT,
    INACT,
    INACT_ACT,
    STP_PSM_MAX_STATE,
}MTKSTP_PSM_STATE_T;

typedef enum _ENUM_STP_OPID_T {
    STP_OPID_PSM_SLEEP = 0,
    STP_OPID_PSM_WAKEUP,
    STP_OPID_PSM_HOST_AWAKE,
    STP_OPID_PSM_EXIT,
    STP_OPID_PSM_NUM
} ENUM_STP_OPID_T, *P_ENUM_STP_OPID_T;

typedef enum {
    MON=0,
    UNMON,
}MTKSTP_PSM_MONSTATE_T;

typedef INT32 (*wmt_notify_t)(MTKSTP_PSM_ACTION_T action);
typedef INT32 (*stp_tx_cb_t)(unsigned  char*buffer, UINT32 length, UINT8 type);

typedef OSAL_OP_DAT STP_OP;
typedef P_OSAL_OP_DAT P_STP_OP;

typedef struct mtk_stp_psm
{
    OSAL_THREAD             PSMd;   /* main thread (wmtd) handle */
    OSAL_EVENT              STPd_event;
    
    OSAL_OP_Q               rFreeOpQ; /* free op queue */
    OSAL_OP_Q               rActiveOpQ; /* active op queue */
    OSAL_OP                 arQue[STP_OP_BUF_SIZE]; /* real op instances */

	P_OSAL_OP               current_active_op;
    MTKSTP_PSM_STATE_T      work_state; /*working state*/
    INT32                   flag;
//    OSAL_UNSLEEPABLE_LOCK   flagSpinlock;
    INT32                   idle_time_to_sleep;
    OSAL_WAKE_LOCK          wake_lock;
    OSAL_TIMER              psm_timer;  /*monitor if active*/
    OSAL_EVENT                wait_wmt_q;
    OSAL_FIFO               hold_fifo;
    OSAL_UNSLEEPABLE_LOCK   hold_fifo_spinlock_global;
    OSAL_UNSLEEPABLE_LOCK   wq_spinlock;
    OSAL_SLEEPABLE_LOCK     user_lock;
    INT32                   (*wmt_notify)(MTKSTP_PSM_ACTION_T action);
    INT32                   (*stp_tx_cb)(unsigned  char*buffer,UINT32 length, UINT8 type);
    UINT8                   out_buf[STP_PSM_TX_SIZE];
}MTKSTP_PSM_T;

/*******************************************************************************
*                            P U B L I C   D A T A
********************************************************************************
*/

/*******************************************************************************
*                           P R I V A T E   D A T A
********************************************************************************
*/

/*******************************************************************************
*                  F U N C T I O N   D E C L A R A T I O N S
********************************************************************************
*/
/*stp-psm external function*/
INT32 stp_psm_notify_stp(MTKSTP_PSM_T *stp_psm, const MTKSTP_PSM_ACTION_T action);
INT32 stp_psm_notify_wmt_wakeup(MTKSTP_PSM_T *stp_psm);
INT32 stp_psm_notify_wmt_sleep(MTKSTP_PSM_T *stp_psm);

INT32 stp_psm_start_monitor(MTKSTP_PSM_T *stp_psm);
INT32 stp_psm_is_to_block_traffic(MTKSTP_PSM_T * stp_psm);
INT32 stp_psm_is_disable(MTKSTP_PSM_T * stp_psm);
INT32 stp_psm_has_pending_data(MTKSTP_PSM_T * stp_psm);
INT32 stp_psm_release_data(MTKSTP_PSM_T *stp_psm);
INT32 stp_psm_hold_data (
    MTKSTP_PSM_T *stp_psm,
    const UINT8 *buffer,
    const UINT32 len,
    const UINT8 type
    );
INT32 stp_psm_do_wakeup(MTKSTP_PSM_T *stp_psm);

#if  defined(MT6628) && defined(MTK_COMBO_QUICK_SLEEP_SUPPORT) && defined(MTK_COMBO_QUICK_SLEEP_SUPPORT_OPEN)
INT32 stp_psm_disable_by_tx_rx_density(MTKSTP_PSM_T *stp_psm, INT32 dir);
#endif 

INT32 stp_psm_reset(MTKSTP_PSM_T *stp_psm);
INT32 stp_psm_disable(MTKSTP_PSM_T *stp_psm);
INT32 stp_psm_enable(MTKSTP_PSM_T *stp_psm, INT32 idle_time_to_sleep);
struct mtk_stp_psm *stp_psm_init(void);
INT32 stp_psm_deinit(MTKSTP_PSM_T *stp_psm);
MTK_WCN_BOOL mtk_wcn_stp_psm_dbg_level(UINT32 dbglevel);
INT32 stp_psm_sleep_for_thermal(MTKSTP_PSM_T *stp_psm);

/*******************************************************************************
*                              F U N C T I O N S
********************************************************************************
*/

#endif 

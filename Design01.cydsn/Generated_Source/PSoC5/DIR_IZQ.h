/*******************************************************************************
* File Name: DIR_IZQ.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_DIR_IZQ_H) /* Pins DIR_IZQ_H */
#define CY_PINS_DIR_IZQ_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DIR_IZQ_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DIR_IZQ__PORT == 15 && ((DIR_IZQ__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DIR_IZQ_Write(uint8 value);
void    DIR_IZQ_SetDriveMode(uint8 mode);
uint8   DIR_IZQ_ReadDataReg(void);
uint8   DIR_IZQ_Read(void);
void    DIR_IZQ_SetInterruptMode(uint16 position, uint16 mode);
uint8   DIR_IZQ_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DIR_IZQ_SetDriveMode() function.
     *  @{
     */
        #define DIR_IZQ_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DIR_IZQ_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DIR_IZQ_DM_RES_UP          PIN_DM_RES_UP
        #define DIR_IZQ_DM_RES_DWN         PIN_DM_RES_DWN
        #define DIR_IZQ_DM_OD_LO           PIN_DM_OD_LO
        #define DIR_IZQ_DM_OD_HI           PIN_DM_OD_HI
        #define DIR_IZQ_DM_STRONG          PIN_DM_STRONG
        #define DIR_IZQ_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DIR_IZQ_MASK               DIR_IZQ__MASK
#define DIR_IZQ_SHIFT              DIR_IZQ__SHIFT
#define DIR_IZQ_WIDTH              1u

/* Interrupt constants */
#if defined(DIR_IZQ__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DIR_IZQ_SetInterruptMode() function.
     *  @{
     */
        #define DIR_IZQ_INTR_NONE      (uint16)(0x0000u)
        #define DIR_IZQ_INTR_RISING    (uint16)(0x0001u)
        #define DIR_IZQ_INTR_FALLING   (uint16)(0x0002u)
        #define DIR_IZQ_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DIR_IZQ_INTR_MASK      (0x01u) 
#endif /* (DIR_IZQ__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DIR_IZQ_PS                     (* (reg8 *) DIR_IZQ__PS)
/* Data Register */
#define DIR_IZQ_DR                     (* (reg8 *) DIR_IZQ__DR)
/* Port Number */
#define DIR_IZQ_PRT_NUM                (* (reg8 *) DIR_IZQ__PRT) 
/* Connect to Analog Globals */                                                  
#define DIR_IZQ_AG                     (* (reg8 *) DIR_IZQ__AG)                       
/* Analog MUX bux enable */
#define DIR_IZQ_AMUX                   (* (reg8 *) DIR_IZQ__AMUX) 
/* Bidirectional Enable */                                                        
#define DIR_IZQ_BIE                    (* (reg8 *) DIR_IZQ__BIE)
/* Bit-mask for Aliased Register Access */
#define DIR_IZQ_BIT_MASK               (* (reg8 *) DIR_IZQ__BIT_MASK)
/* Bypass Enable */
#define DIR_IZQ_BYP                    (* (reg8 *) DIR_IZQ__BYP)
/* Port wide control signals */                                                   
#define DIR_IZQ_CTL                    (* (reg8 *) DIR_IZQ__CTL)
/* Drive Modes */
#define DIR_IZQ_DM0                    (* (reg8 *) DIR_IZQ__DM0) 
#define DIR_IZQ_DM1                    (* (reg8 *) DIR_IZQ__DM1)
#define DIR_IZQ_DM2                    (* (reg8 *) DIR_IZQ__DM2) 
/* Input Buffer Disable Override */
#define DIR_IZQ_INP_DIS                (* (reg8 *) DIR_IZQ__INP_DIS)
/* LCD Common or Segment Drive */
#define DIR_IZQ_LCD_COM_SEG            (* (reg8 *) DIR_IZQ__LCD_COM_SEG)
/* Enable Segment LCD */
#define DIR_IZQ_LCD_EN                 (* (reg8 *) DIR_IZQ__LCD_EN)
/* Slew Rate Control */
#define DIR_IZQ_SLW                    (* (reg8 *) DIR_IZQ__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DIR_IZQ_PRTDSI__CAPS_SEL       (* (reg8 *) DIR_IZQ__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DIR_IZQ_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DIR_IZQ__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DIR_IZQ_PRTDSI__OE_SEL0        (* (reg8 *) DIR_IZQ__PRTDSI__OE_SEL0) 
#define DIR_IZQ_PRTDSI__OE_SEL1        (* (reg8 *) DIR_IZQ__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DIR_IZQ_PRTDSI__OUT_SEL0       (* (reg8 *) DIR_IZQ__PRTDSI__OUT_SEL0) 
#define DIR_IZQ_PRTDSI__OUT_SEL1       (* (reg8 *) DIR_IZQ__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DIR_IZQ_PRTDSI__SYNC_OUT       (* (reg8 *) DIR_IZQ__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DIR_IZQ__SIO_CFG)
    #define DIR_IZQ_SIO_HYST_EN        (* (reg8 *) DIR_IZQ__SIO_HYST_EN)
    #define DIR_IZQ_SIO_REG_HIFREQ     (* (reg8 *) DIR_IZQ__SIO_REG_HIFREQ)
    #define DIR_IZQ_SIO_CFG            (* (reg8 *) DIR_IZQ__SIO_CFG)
    #define DIR_IZQ_SIO_DIFF           (* (reg8 *) DIR_IZQ__SIO_DIFF)
#endif /* (DIR_IZQ__SIO_CFG) */

/* Interrupt Registers */
#if defined(DIR_IZQ__INTSTAT)
    #define DIR_IZQ_INTSTAT            (* (reg8 *) DIR_IZQ__INTSTAT)
    #define DIR_IZQ_SNAP               (* (reg8 *) DIR_IZQ__SNAP)
    
	#define DIR_IZQ_0_INTTYPE_REG 		(* (reg8 *) DIR_IZQ__0__INTTYPE)
#endif /* (DIR_IZQ__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DIR_IZQ_H */


/* [] END OF FILE */

/*******************************************************************************
* File Name: DIR_DER.h  
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

#if !defined(CY_PINS_DIR_DER_H) /* Pins DIR_DER_H */
#define CY_PINS_DIR_DER_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DIR_DER_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DIR_DER__PORT == 15 && ((DIR_DER__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DIR_DER_Write(uint8 value);
void    DIR_DER_SetDriveMode(uint8 mode);
uint8   DIR_DER_ReadDataReg(void);
uint8   DIR_DER_Read(void);
void    DIR_DER_SetInterruptMode(uint16 position, uint16 mode);
uint8   DIR_DER_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DIR_DER_SetDriveMode() function.
     *  @{
     */
        #define DIR_DER_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DIR_DER_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DIR_DER_DM_RES_UP          PIN_DM_RES_UP
        #define DIR_DER_DM_RES_DWN         PIN_DM_RES_DWN
        #define DIR_DER_DM_OD_LO           PIN_DM_OD_LO
        #define DIR_DER_DM_OD_HI           PIN_DM_OD_HI
        #define DIR_DER_DM_STRONG          PIN_DM_STRONG
        #define DIR_DER_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DIR_DER_MASK               DIR_DER__MASK
#define DIR_DER_SHIFT              DIR_DER__SHIFT
#define DIR_DER_WIDTH              1u

/* Interrupt constants */
#if defined(DIR_DER__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DIR_DER_SetInterruptMode() function.
     *  @{
     */
        #define DIR_DER_INTR_NONE      (uint16)(0x0000u)
        #define DIR_DER_INTR_RISING    (uint16)(0x0001u)
        #define DIR_DER_INTR_FALLING   (uint16)(0x0002u)
        #define DIR_DER_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DIR_DER_INTR_MASK      (0x01u) 
#endif /* (DIR_DER__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DIR_DER_PS                     (* (reg8 *) DIR_DER__PS)
/* Data Register */
#define DIR_DER_DR                     (* (reg8 *) DIR_DER__DR)
/* Port Number */
#define DIR_DER_PRT_NUM                (* (reg8 *) DIR_DER__PRT) 
/* Connect to Analog Globals */                                                  
#define DIR_DER_AG                     (* (reg8 *) DIR_DER__AG)                       
/* Analog MUX bux enable */
#define DIR_DER_AMUX                   (* (reg8 *) DIR_DER__AMUX) 
/* Bidirectional Enable */                                                        
#define DIR_DER_BIE                    (* (reg8 *) DIR_DER__BIE)
/* Bit-mask for Aliased Register Access */
#define DIR_DER_BIT_MASK               (* (reg8 *) DIR_DER__BIT_MASK)
/* Bypass Enable */
#define DIR_DER_BYP                    (* (reg8 *) DIR_DER__BYP)
/* Port wide control signals */                                                   
#define DIR_DER_CTL                    (* (reg8 *) DIR_DER__CTL)
/* Drive Modes */
#define DIR_DER_DM0                    (* (reg8 *) DIR_DER__DM0) 
#define DIR_DER_DM1                    (* (reg8 *) DIR_DER__DM1)
#define DIR_DER_DM2                    (* (reg8 *) DIR_DER__DM2) 
/* Input Buffer Disable Override */
#define DIR_DER_INP_DIS                (* (reg8 *) DIR_DER__INP_DIS)
/* LCD Common or Segment Drive */
#define DIR_DER_LCD_COM_SEG            (* (reg8 *) DIR_DER__LCD_COM_SEG)
/* Enable Segment LCD */
#define DIR_DER_LCD_EN                 (* (reg8 *) DIR_DER__LCD_EN)
/* Slew Rate Control */
#define DIR_DER_SLW                    (* (reg8 *) DIR_DER__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DIR_DER_PRTDSI__CAPS_SEL       (* (reg8 *) DIR_DER__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DIR_DER_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DIR_DER__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DIR_DER_PRTDSI__OE_SEL0        (* (reg8 *) DIR_DER__PRTDSI__OE_SEL0) 
#define DIR_DER_PRTDSI__OE_SEL1        (* (reg8 *) DIR_DER__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DIR_DER_PRTDSI__OUT_SEL0       (* (reg8 *) DIR_DER__PRTDSI__OUT_SEL0) 
#define DIR_DER_PRTDSI__OUT_SEL1       (* (reg8 *) DIR_DER__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DIR_DER_PRTDSI__SYNC_OUT       (* (reg8 *) DIR_DER__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DIR_DER__SIO_CFG)
    #define DIR_DER_SIO_HYST_EN        (* (reg8 *) DIR_DER__SIO_HYST_EN)
    #define DIR_DER_SIO_REG_HIFREQ     (* (reg8 *) DIR_DER__SIO_REG_HIFREQ)
    #define DIR_DER_SIO_CFG            (* (reg8 *) DIR_DER__SIO_CFG)
    #define DIR_DER_SIO_DIFF           (* (reg8 *) DIR_DER__SIO_DIFF)
#endif /* (DIR_DER__SIO_CFG) */

/* Interrupt Registers */
#if defined(DIR_DER__INTSTAT)
    #define DIR_DER_INTSTAT            (* (reg8 *) DIR_DER__INTSTAT)
    #define DIR_DER_SNAP               (* (reg8 *) DIR_DER__SNAP)
    
	#define DIR_DER_0_INTTYPE_REG 		(* (reg8 *) DIR_DER__0__INTTYPE)
#endif /* (DIR_DER__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DIR_DER_H */


/* [] END OF FILE */

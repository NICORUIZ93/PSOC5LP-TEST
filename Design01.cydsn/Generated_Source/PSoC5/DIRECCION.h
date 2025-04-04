/*******************************************************************************
* File Name: DIRECCION.h  
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

#if !defined(CY_PINS_DIRECCION_H) /* Pins DIRECCION_H */
#define CY_PINS_DIRECCION_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DIRECCION_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DIRECCION__PORT == 15 && ((DIRECCION__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DIRECCION_Write(uint8 value);
void    DIRECCION_SetDriveMode(uint8 mode);
uint8   DIRECCION_ReadDataReg(void);
uint8   DIRECCION_Read(void);
void    DIRECCION_SetInterruptMode(uint16 position, uint16 mode);
uint8   DIRECCION_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DIRECCION_SetDriveMode() function.
     *  @{
     */
        #define DIRECCION_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DIRECCION_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DIRECCION_DM_RES_UP          PIN_DM_RES_UP
        #define DIRECCION_DM_RES_DWN         PIN_DM_RES_DWN
        #define DIRECCION_DM_OD_LO           PIN_DM_OD_LO
        #define DIRECCION_DM_OD_HI           PIN_DM_OD_HI
        #define DIRECCION_DM_STRONG          PIN_DM_STRONG
        #define DIRECCION_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DIRECCION_MASK               DIRECCION__MASK
#define DIRECCION_SHIFT              DIRECCION__SHIFT
#define DIRECCION_WIDTH              1u

/* Interrupt constants */
#if defined(DIRECCION__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DIRECCION_SetInterruptMode() function.
     *  @{
     */
        #define DIRECCION_INTR_NONE      (uint16)(0x0000u)
        #define DIRECCION_INTR_RISING    (uint16)(0x0001u)
        #define DIRECCION_INTR_FALLING   (uint16)(0x0002u)
        #define DIRECCION_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DIRECCION_INTR_MASK      (0x01u) 
#endif /* (DIRECCION__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DIRECCION_PS                     (* (reg8 *) DIRECCION__PS)
/* Data Register */
#define DIRECCION_DR                     (* (reg8 *) DIRECCION__DR)
/* Port Number */
#define DIRECCION_PRT_NUM                (* (reg8 *) DIRECCION__PRT) 
/* Connect to Analog Globals */                                                  
#define DIRECCION_AG                     (* (reg8 *) DIRECCION__AG)                       
/* Analog MUX bux enable */
#define DIRECCION_AMUX                   (* (reg8 *) DIRECCION__AMUX) 
/* Bidirectional Enable */                                                        
#define DIRECCION_BIE                    (* (reg8 *) DIRECCION__BIE)
/* Bit-mask for Aliased Register Access */
#define DIRECCION_BIT_MASK               (* (reg8 *) DIRECCION__BIT_MASK)
/* Bypass Enable */
#define DIRECCION_BYP                    (* (reg8 *) DIRECCION__BYP)
/* Port wide control signals */                                                   
#define DIRECCION_CTL                    (* (reg8 *) DIRECCION__CTL)
/* Drive Modes */
#define DIRECCION_DM0                    (* (reg8 *) DIRECCION__DM0) 
#define DIRECCION_DM1                    (* (reg8 *) DIRECCION__DM1)
#define DIRECCION_DM2                    (* (reg8 *) DIRECCION__DM2) 
/* Input Buffer Disable Override */
#define DIRECCION_INP_DIS                (* (reg8 *) DIRECCION__INP_DIS)
/* LCD Common or Segment Drive */
#define DIRECCION_LCD_COM_SEG            (* (reg8 *) DIRECCION__LCD_COM_SEG)
/* Enable Segment LCD */
#define DIRECCION_LCD_EN                 (* (reg8 *) DIRECCION__LCD_EN)
/* Slew Rate Control */
#define DIRECCION_SLW                    (* (reg8 *) DIRECCION__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DIRECCION_PRTDSI__CAPS_SEL       (* (reg8 *) DIRECCION__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DIRECCION_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DIRECCION__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DIRECCION_PRTDSI__OE_SEL0        (* (reg8 *) DIRECCION__PRTDSI__OE_SEL0) 
#define DIRECCION_PRTDSI__OE_SEL1        (* (reg8 *) DIRECCION__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DIRECCION_PRTDSI__OUT_SEL0       (* (reg8 *) DIRECCION__PRTDSI__OUT_SEL0) 
#define DIRECCION_PRTDSI__OUT_SEL1       (* (reg8 *) DIRECCION__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DIRECCION_PRTDSI__SYNC_OUT       (* (reg8 *) DIRECCION__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DIRECCION__SIO_CFG)
    #define DIRECCION_SIO_HYST_EN        (* (reg8 *) DIRECCION__SIO_HYST_EN)
    #define DIRECCION_SIO_REG_HIFREQ     (* (reg8 *) DIRECCION__SIO_REG_HIFREQ)
    #define DIRECCION_SIO_CFG            (* (reg8 *) DIRECCION__SIO_CFG)
    #define DIRECCION_SIO_DIFF           (* (reg8 *) DIRECCION__SIO_DIFF)
#endif /* (DIRECCION__SIO_CFG) */

/* Interrupt Registers */
#if defined(DIRECCION__INTSTAT)
    #define DIRECCION_INTSTAT            (* (reg8 *) DIRECCION__INTSTAT)
    #define DIRECCION_SNAP               (* (reg8 *) DIRECCION__SNAP)
    
	#define DIRECCION_0_INTTYPE_REG 		(* (reg8 *) DIRECCION__0__INTTYPE)
#endif /* (DIRECCION__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DIRECCION_H */


/* [] END OF FILE */

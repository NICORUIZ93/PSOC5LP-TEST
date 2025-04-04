/*******************************************************************************
* File Name: DIRECCION_ADELANTE.h  
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

#if !defined(CY_PINS_DIRECCION_ADELANTE_H) /* Pins DIRECCION_ADELANTE_H */
#define CY_PINS_DIRECCION_ADELANTE_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DIRECCION_ADELANTE_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DIRECCION_ADELANTE__PORT == 15 && ((DIRECCION_ADELANTE__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DIRECCION_ADELANTE_Write(uint8 value);
void    DIRECCION_ADELANTE_SetDriveMode(uint8 mode);
uint8   DIRECCION_ADELANTE_ReadDataReg(void);
uint8   DIRECCION_ADELANTE_Read(void);
void    DIRECCION_ADELANTE_SetInterruptMode(uint16 position, uint16 mode);
uint8   DIRECCION_ADELANTE_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DIRECCION_ADELANTE_SetDriveMode() function.
     *  @{
     */
        #define DIRECCION_ADELANTE_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DIRECCION_ADELANTE_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DIRECCION_ADELANTE_DM_RES_UP          PIN_DM_RES_UP
        #define DIRECCION_ADELANTE_DM_RES_DWN         PIN_DM_RES_DWN
        #define DIRECCION_ADELANTE_DM_OD_LO           PIN_DM_OD_LO
        #define DIRECCION_ADELANTE_DM_OD_HI           PIN_DM_OD_HI
        #define DIRECCION_ADELANTE_DM_STRONG          PIN_DM_STRONG
        #define DIRECCION_ADELANTE_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DIRECCION_ADELANTE_MASK               DIRECCION_ADELANTE__MASK
#define DIRECCION_ADELANTE_SHIFT              DIRECCION_ADELANTE__SHIFT
#define DIRECCION_ADELANTE_WIDTH              1u

/* Interrupt constants */
#if defined(DIRECCION_ADELANTE__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DIRECCION_ADELANTE_SetInterruptMode() function.
     *  @{
     */
        #define DIRECCION_ADELANTE_INTR_NONE      (uint16)(0x0000u)
        #define DIRECCION_ADELANTE_INTR_RISING    (uint16)(0x0001u)
        #define DIRECCION_ADELANTE_INTR_FALLING   (uint16)(0x0002u)
        #define DIRECCION_ADELANTE_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DIRECCION_ADELANTE_INTR_MASK      (0x01u) 
#endif /* (DIRECCION_ADELANTE__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DIRECCION_ADELANTE_PS                     (* (reg8 *) DIRECCION_ADELANTE__PS)
/* Data Register */
#define DIRECCION_ADELANTE_DR                     (* (reg8 *) DIRECCION_ADELANTE__DR)
/* Port Number */
#define DIRECCION_ADELANTE_PRT_NUM                (* (reg8 *) DIRECCION_ADELANTE__PRT) 
/* Connect to Analog Globals */                                                  
#define DIRECCION_ADELANTE_AG                     (* (reg8 *) DIRECCION_ADELANTE__AG)                       
/* Analog MUX bux enable */
#define DIRECCION_ADELANTE_AMUX                   (* (reg8 *) DIRECCION_ADELANTE__AMUX) 
/* Bidirectional Enable */                                                        
#define DIRECCION_ADELANTE_BIE                    (* (reg8 *) DIRECCION_ADELANTE__BIE)
/* Bit-mask for Aliased Register Access */
#define DIRECCION_ADELANTE_BIT_MASK               (* (reg8 *) DIRECCION_ADELANTE__BIT_MASK)
/* Bypass Enable */
#define DIRECCION_ADELANTE_BYP                    (* (reg8 *) DIRECCION_ADELANTE__BYP)
/* Port wide control signals */                                                   
#define DIRECCION_ADELANTE_CTL                    (* (reg8 *) DIRECCION_ADELANTE__CTL)
/* Drive Modes */
#define DIRECCION_ADELANTE_DM0                    (* (reg8 *) DIRECCION_ADELANTE__DM0) 
#define DIRECCION_ADELANTE_DM1                    (* (reg8 *) DIRECCION_ADELANTE__DM1)
#define DIRECCION_ADELANTE_DM2                    (* (reg8 *) DIRECCION_ADELANTE__DM2) 
/* Input Buffer Disable Override */
#define DIRECCION_ADELANTE_INP_DIS                (* (reg8 *) DIRECCION_ADELANTE__INP_DIS)
/* LCD Common or Segment Drive */
#define DIRECCION_ADELANTE_LCD_COM_SEG            (* (reg8 *) DIRECCION_ADELANTE__LCD_COM_SEG)
/* Enable Segment LCD */
#define DIRECCION_ADELANTE_LCD_EN                 (* (reg8 *) DIRECCION_ADELANTE__LCD_EN)
/* Slew Rate Control */
#define DIRECCION_ADELANTE_SLW                    (* (reg8 *) DIRECCION_ADELANTE__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DIRECCION_ADELANTE_PRTDSI__CAPS_SEL       (* (reg8 *) DIRECCION_ADELANTE__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DIRECCION_ADELANTE_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DIRECCION_ADELANTE__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DIRECCION_ADELANTE_PRTDSI__OE_SEL0        (* (reg8 *) DIRECCION_ADELANTE__PRTDSI__OE_SEL0) 
#define DIRECCION_ADELANTE_PRTDSI__OE_SEL1        (* (reg8 *) DIRECCION_ADELANTE__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DIRECCION_ADELANTE_PRTDSI__OUT_SEL0       (* (reg8 *) DIRECCION_ADELANTE__PRTDSI__OUT_SEL0) 
#define DIRECCION_ADELANTE_PRTDSI__OUT_SEL1       (* (reg8 *) DIRECCION_ADELANTE__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DIRECCION_ADELANTE_PRTDSI__SYNC_OUT       (* (reg8 *) DIRECCION_ADELANTE__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DIRECCION_ADELANTE__SIO_CFG)
    #define DIRECCION_ADELANTE_SIO_HYST_EN        (* (reg8 *) DIRECCION_ADELANTE__SIO_HYST_EN)
    #define DIRECCION_ADELANTE_SIO_REG_HIFREQ     (* (reg8 *) DIRECCION_ADELANTE__SIO_REG_HIFREQ)
    #define DIRECCION_ADELANTE_SIO_CFG            (* (reg8 *) DIRECCION_ADELANTE__SIO_CFG)
    #define DIRECCION_ADELANTE_SIO_DIFF           (* (reg8 *) DIRECCION_ADELANTE__SIO_DIFF)
#endif /* (DIRECCION_ADELANTE__SIO_CFG) */

/* Interrupt Registers */
#if defined(DIRECCION_ADELANTE__INTSTAT)
    #define DIRECCION_ADELANTE_INTSTAT            (* (reg8 *) DIRECCION_ADELANTE__INTSTAT)
    #define DIRECCION_ADELANTE_SNAP               (* (reg8 *) DIRECCION_ADELANTE__SNAP)
    
	#define DIRECCION_ADELANTE_0_INTTYPE_REG 		(* (reg8 *) DIRECCION_ADELANTE__0__INTTYPE)
#endif /* (DIRECCION_ADELANTE__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DIRECCION_ADELANTE_H */


/* [] END OF FILE */

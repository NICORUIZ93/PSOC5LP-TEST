/*******************************************************************************
* File Name: DIRECCION_ATRAS.h  
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

#if !defined(CY_PINS_DIRECCION_ATRAS_H) /* Pins DIRECCION_ATRAS_H */
#define CY_PINS_DIRECCION_ATRAS_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DIRECCION_ATRAS_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DIRECCION_ATRAS__PORT == 15 && ((DIRECCION_ATRAS__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DIRECCION_ATRAS_Write(uint8 value);
void    DIRECCION_ATRAS_SetDriveMode(uint8 mode);
uint8   DIRECCION_ATRAS_ReadDataReg(void);
uint8   DIRECCION_ATRAS_Read(void);
void    DIRECCION_ATRAS_SetInterruptMode(uint16 position, uint16 mode);
uint8   DIRECCION_ATRAS_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DIRECCION_ATRAS_SetDriveMode() function.
     *  @{
     */
        #define DIRECCION_ATRAS_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DIRECCION_ATRAS_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DIRECCION_ATRAS_DM_RES_UP          PIN_DM_RES_UP
        #define DIRECCION_ATRAS_DM_RES_DWN         PIN_DM_RES_DWN
        #define DIRECCION_ATRAS_DM_OD_LO           PIN_DM_OD_LO
        #define DIRECCION_ATRAS_DM_OD_HI           PIN_DM_OD_HI
        #define DIRECCION_ATRAS_DM_STRONG          PIN_DM_STRONG
        #define DIRECCION_ATRAS_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DIRECCION_ATRAS_MASK               DIRECCION_ATRAS__MASK
#define DIRECCION_ATRAS_SHIFT              DIRECCION_ATRAS__SHIFT
#define DIRECCION_ATRAS_WIDTH              1u

/* Interrupt constants */
#if defined(DIRECCION_ATRAS__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DIRECCION_ATRAS_SetInterruptMode() function.
     *  @{
     */
        #define DIRECCION_ATRAS_INTR_NONE      (uint16)(0x0000u)
        #define DIRECCION_ATRAS_INTR_RISING    (uint16)(0x0001u)
        #define DIRECCION_ATRAS_INTR_FALLING   (uint16)(0x0002u)
        #define DIRECCION_ATRAS_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DIRECCION_ATRAS_INTR_MASK      (0x01u) 
#endif /* (DIRECCION_ATRAS__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DIRECCION_ATRAS_PS                     (* (reg8 *) DIRECCION_ATRAS__PS)
/* Data Register */
#define DIRECCION_ATRAS_DR                     (* (reg8 *) DIRECCION_ATRAS__DR)
/* Port Number */
#define DIRECCION_ATRAS_PRT_NUM                (* (reg8 *) DIRECCION_ATRAS__PRT) 
/* Connect to Analog Globals */                                                  
#define DIRECCION_ATRAS_AG                     (* (reg8 *) DIRECCION_ATRAS__AG)                       
/* Analog MUX bux enable */
#define DIRECCION_ATRAS_AMUX                   (* (reg8 *) DIRECCION_ATRAS__AMUX) 
/* Bidirectional Enable */                                                        
#define DIRECCION_ATRAS_BIE                    (* (reg8 *) DIRECCION_ATRAS__BIE)
/* Bit-mask for Aliased Register Access */
#define DIRECCION_ATRAS_BIT_MASK               (* (reg8 *) DIRECCION_ATRAS__BIT_MASK)
/* Bypass Enable */
#define DIRECCION_ATRAS_BYP                    (* (reg8 *) DIRECCION_ATRAS__BYP)
/* Port wide control signals */                                                   
#define DIRECCION_ATRAS_CTL                    (* (reg8 *) DIRECCION_ATRAS__CTL)
/* Drive Modes */
#define DIRECCION_ATRAS_DM0                    (* (reg8 *) DIRECCION_ATRAS__DM0) 
#define DIRECCION_ATRAS_DM1                    (* (reg8 *) DIRECCION_ATRAS__DM1)
#define DIRECCION_ATRAS_DM2                    (* (reg8 *) DIRECCION_ATRAS__DM2) 
/* Input Buffer Disable Override */
#define DIRECCION_ATRAS_INP_DIS                (* (reg8 *) DIRECCION_ATRAS__INP_DIS)
/* LCD Common or Segment Drive */
#define DIRECCION_ATRAS_LCD_COM_SEG            (* (reg8 *) DIRECCION_ATRAS__LCD_COM_SEG)
/* Enable Segment LCD */
#define DIRECCION_ATRAS_LCD_EN                 (* (reg8 *) DIRECCION_ATRAS__LCD_EN)
/* Slew Rate Control */
#define DIRECCION_ATRAS_SLW                    (* (reg8 *) DIRECCION_ATRAS__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DIRECCION_ATRAS_PRTDSI__CAPS_SEL       (* (reg8 *) DIRECCION_ATRAS__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DIRECCION_ATRAS_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DIRECCION_ATRAS__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DIRECCION_ATRAS_PRTDSI__OE_SEL0        (* (reg8 *) DIRECCION_ATRAS__PRTDSI__OE_SEL0) 
#define DIRECCION_ATRAS_PRTDSI__OE_SEL1        (* (reg8 *) DIRECCION_ATRAS__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DIRECCION_ATRAS_PRTDSI__OUT_SEL0       (* (reg8 *) DIRECCION_ATRAS__PRTDSI__OUT_SEL0) 
#define DIRECCION_ATRAS_PRTDSI__OUT_SEL1       (* (reg8 *) DIRECCION_ATRAS__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DIRECCION_ATRAS_PRTDSI__SYNC_OUT       (* (reg8 *) DIRECCION_ATRAS__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DIRECCION_ATRAS__SIO_CFG)
    #define DIRECCION_ATRAS_SIO_HYST_EN        (* (reg8 *) DIRECCION_ATRAS__SIO_HYST_EN)
    #define DIRECCION_ATRAS_SIO_REG_HIFREQ     (* (reg8 *) DIRECCION_ATRAS__SIO_REG_HIFREQ)
    #define DIRECCION_ATRAS_SIO_CFG            (* (reg8 *) DIRECCION_ATRAS__SIO_CFG)
    #define DIRECCION_ATRAS_SIO_DIFF           (* (reg8 *) DIRECCION_ATRAS__SIO_DIFF)
#endif /* (DIRECCION_ATRAS__SIO_CFG) */

/* Interrupt Registers */
#if defined(DIRECCION_ATRAS__INTSTAT)
    #define DIRECCION_ATRAS_INTSTAT            (* (reg8 *) DIRECCION_ATRAS__INTSTAT)
    #define DIRECCION_ATRAS_SNAP               (* (reg8 *) DIRECCION_ATRAS__SNAP)
    
	#define DIRECCION_ATRAS_0_INTTYPE_REG 		(* (reg8 *) DIRECCION_ATRAS__0__INTTYPE)
#endif /* (DIRECCION_ATRAS__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DIRECCION_ATRAS_H */


/* [] END OF FILE */

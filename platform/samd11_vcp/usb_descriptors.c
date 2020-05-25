/*
 * Copyright (c) 2017, Alex Taradov <alex@taradov.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */


/*- Includes ----------------------------------------------------------------*/
#include <stdalign.h>
#include "usb.h"
#include "usb_descriptors.h"

/*- Variables ---------------------------------------------------------------*/
const alignas(4) usb_device_descriptor_t usb_device_descriptor =
{
  .bLength            = sizeof(usb_device_descriptor_t),
  .bDescriptorType    = USB_DEVICE_DESCRIPTOR,
  .bcdUSB             = 0x0200,
  .bDeviceClass       = USB_DEVICE_CLASS_MISCELLANEOUS,
  .bDeviceSubClass    = USB_DEVICE_SUBCLASS_COMMON,
  .bDeviceProtocol    = USB_DEVICE_PROTOCOL_INTERFACE_ASSOCIATION,
  .bMaxPacketSize0    = 64,
  .idVendor           = 0x6666,
  .idProduct          = 0x6600,
  .bcdDevice          = 0x0101,
  .iManufacturer      = USB_STR_MANUFACTURER,
  .iProduct           = USB_STR_PRODUCT,
  .iSerialNumber      = USB_STR_SERIAL_NUMBER,
  .bNumConfigurations = 1,
};

const alignas(4) usb_configuration_hierarchy_t usb_configuration_hierarchy =
{
  .configuration =
  {
    .bLength             = sizeof(usb_configuration_descriptor_t),
    .bDescriptorType     = USB_CONFIGURATION_DESCRIPTOR,
    .wTotalLength        = sizeof(usb_configuration_hierarchy_t),
    .bNumInterfaces      = 4,
    .bConfigurationValue = 1,
    .iConfiguration      = 0,
    .bmAttributes        = 0x80,
    .bMaxPower           = 250, // 500 mA
  },

        .hid_interface =
                {
                        .bLength             = sizeof(usb_interface_descriptor_t),
                        .bDescriptorType     = USB_INTERFACE_DESCRIPTOR,
                        .bInterfaceNumber    = 0,
                        .bAlternateSetting   = 0,
                        .bNumEndpoints       = 2,
                        .bInterfaceClass     = USB_HID_DEVICE_CLASS,
                        .bInterfaceSubClass  = 0,
                        .bInterfaceProtocol  = 0,
                        .iInterface          = USB_STR_CMSIS_DAP,
                },

        .hid =
                {
                        .bLength             = sizeof(usb_hid_descriptor_t),
                        .bDescriptorType     = USB_HID_DESCRIPTOR,
                        .bcdHID              = 0x0111,
                        .bCountryCode        = 0,
                        .bNumDescriptors     = 1,
                        .bDescriptorType1    = USB_HID_REPORT_DESCRIPTOR,
                        .wDescriptorLength   = sizeof(usb_hid_report_descriptor),
                },

        .hid_ep_in =
                {
                        .bLength             = sizeof(usb_endpoint_descriptor_t),
                        .bDescriptorType     = USB_ENDPOINT_DESCRIPTOR,
                        .bEndpointAddress    = USB_IN_ENDPOINT | USB_HID_EP_SEND,
                        .bmAttributes        = USB_INTERRUPT_ENDPOINT,
                        .wMaxPacketSize      = 64,
                        .bInterval           = 1,
                },

        .hid_ep_out =
                {
                        .bLength             = sizeof(usb_endpoint_descriptor_t),
                        .bDescriptorType     = USB_ENDPOINT_DESCRIPTOR,
                        .bEndpointAddress    = USB_OUT_ENDPOINT | USB_HID_EP_RECV,
                        .bmAttributes        = USB_INTERRUPT_ENDPOINT,
                        .wMaxPacketSize      = 64,
                        .bInterval           = 1,
                },

        .hid_interface0 =
                {
                        .bLength             = sizeof(usb_interface_descriptor_t),
                        .bDescriptorType     = USB_INTERFACE_DESCRIPTOR,
                        .bInterfaceNumber    = 1,
                        .bAlternateSetting   = 0,
                        .bNumEndpoints       = 2,
                        .bInterfaceClass     = USB_HID_DEVICE_CLASS,
                        .bInterfaceSubClass  = 0,
                        .bInterfaceProtocol  = 0,
                        .iInterface          = USB_STR_CMSIS_DAP,
                },

        .hid0 =
                {
                        .bLength             = sizeof(usb_hid_descriptor_t),
                        .bDescriptorType     = USB_HID_DESCRIPTOR,
                        .bcdHID              = 0x0111,
                        .bCountryCode        = 0,
                        .bNumDescriptors     = 1,
                        .bDescriptorType1    = USB_HID_REPORT_DESCRIPTOR,
                        .wDescriptorLength   = sizeof(usb_hid_report_descriptor),
                },

        .hid_ep_in0 =
                {
                        .bLength             = sizeof(usb_endpoint_descriptor_t),
                        .bDescriptorType     = USB_ENDPOINT_DESCRIPTOR,
                        .bEndpointAddress    = USB_IN_ENDPOINT | USB_HID0_EP_SEND,
                        .bmAttributes        = USB_INTERRUPT_ENDPOINT,
                        .wMaxPacketSize      = 64,
                        .bInterval           = 1,
                },

        .hid_ep_out0 =
                {
                        .bLength             = sizeof(usb_endpoint_descriptor_t),
                        .bDescriptorType     = USB_ENDPOINT_DESCRIPTOR,
                        .bEndpointAddress    = USB_OUT_ENDPOINT | USB_HID0_EP_RECV,
                        .bmAttributes        = USB_INTERRUPT_ENDPOINT,
                        .wMaxPacketSize      = 64,
                        .bInterval           = 1,
                },

  .iad =
  { 
    .bLength             = sizeof(usb_interface_association_descriptor_t),
    .bDescriptorType     = USB_INTERFACE_ASSOCIATION_DESCRIPTOR,
    .bFirstInterface     = 2,
    .bInterfaceCount     = 2,
    .bFunctionClass      = USB_CDC_COMM_CLASS,
    .bFunctionSubClass   = USB_CDC_ACM_SUBCLASS,
    .bFunctionProtocol   = 0,
    .iFunction           = USB_STR_COM_PORT,
  },

  .interface_comm =
  {
    .bLength             = sizeof(usb_interface_descriptor_t),
    .bDescriptorType     = USB_INTERFACE_DESCRIPTOR,
    .bInterfaceNumber    = 2,
    .bAlternateSetting   = 0,
    .bNumEndpoints       = 1,
    .bInterfaceClass     = USB_CDC_COMM_CLASS,
    .bInterfaceSubClass  = USB_CDC_ACM_SUBCLASS,
    .bInterfaceProtocol  = 0,
    .iInterface          = 0,
  },

  .cdc_header =
  {
    .bFunctionalLength   = sizeof(usb_cdc_header_functional_descriptor_t),
    .bDescriptorType     = USB_CS_INTERFACE_DESCRIPTOR,
    .bDescriptorSubtype  = USB_CDC_HEADER_SUBTYPE,
    .bcdCDC              = 0x0110,
  },

  .cdc_acm =
  {
    .bFunctionalLength   = sizeof(usb_cdc_abstract_control_managment_descriptor_t),
    .bDescriptorType     = USB_CS_INTERFACE_DESCRIPTOR,
    .bDescriptorSubtype  = USB_CDC_ACM_SUBTYPE,
    .bmCapabilities      = USB_CDC_ACM_SUPPORT_LINE_REQUESTS,
  },

  .cdc_call_mgmt =
  {
    .bFunctionalLength   = sizeof(usb_cdc_call_managment_functional_descriptor_t),
    .bDescriptorType     = USB_CS_INTERFACE_DESCRIPTOR,
    .bDescriptorSubtype  = USB_CDC_CALL_MGMT_SUBTYPE,
    .bmCapabilities      = USB_CDC_CALL_MGMT_OVER_DCI,
    .bDataInterface      = 3,
  },

  .cdc_union =
  {
    .bFunctionalLength   = sizeof(usb_cdc_union_functional_descriptor_t),
    .bDescriptorType     = USB_CS_INTERFACE_DESCRIPTOR,
    .bDescriptorSubtype  = USB_CDC_UNION_SUBTYPE,
    .bMasterInterface    = 2,
    .bSlaveInterface0    = 3,
  },

  .ep_comm =
  {
    .bLength             = sizeof(usb_endpoint_descriptor_t),
    .bDescriptorType     = USB_ENDPOINT_DESCRIPTOR,
    .bEndpointAddress    = USB_IN_ENDPOINT | USB_CDC_EP_COMM,
    .bmAttributes        = USB_INTERRUPT_ENDPOINT,
    .wMaxPacketSize      = 64,
    .bInterval           = 1,
  },

  .interface_data =
  {
    .bLength             = sizeof(usb_interface_descriptor_t),
    .bDescriptorType     = USB_INTERFACE_DESCRIPTOR,
    .bInterfaceNumber    = 3,
    .bAlternateSetting   = 0,
    .bNumEndpoints       = 2,
    .bInterfaceClass     = USB_CDC_DATA_CLASS,
    .bInterfaceSubClass  = USB_CDC_NO_SUBCLASS,
    .bInterfaceProtocol  = 0,
    .iInterface          = 0,
  },

  .ep_in =
  {
    .bLength             = sizeof(usb_endpoint_descriptor_t),
    .bDescriptorType     = USB_ENDPOINT_DESCRIPTOR,
    .bEndpointAddress    = USB_IN_ENDPOINT | USB_CDC_EP_SEND,
    .bmAttributes        = USB_BULK_ENDPOINT,
    .wMaxPacketSize      = 64,
    .bInterval           = 0,
  },

  .ep_out =
  {
    .bLength             = sizeof(usb_endpoint_descriptor_t),
    .bDescriptorType     = USB_ENDPOINT_DESCRIPTOR,
    .bEndpointAddress    = USB_OUT_ENDPOINT | USB_CDC_EP_RECV,
    .bmAttributes        = USB_BULK_ENDPOINT,
    .wMaxPacketSize      = 64,
    .bInterval           = 0,
  },
};

const alignas(4) uint8_t usb_hid_report_descriptor[33] =
{
  0x06, 0x00, 0xff,  // Usage Page (Vendor Defined 0xFF00)
  0x09, 0x01,        // Usage (0x01)
  0xa1, 0x01,        // Collection (Application)
  0x15, 0x00,        //   Logical Minimum (0)
  0x26, 0xff, 0x00,  //   Logical Maximum (255)
  0x75, 0x08,        //   Report Size (8)
  0x95, 0x40,        //   Report Count (64)
  0x09, 0x01,        //   Usage (0x01)
  0x81, 0x02,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
  0x95, 0x40,        //   Report Count (64)
  0x09, 0x01,        //   Usage (0x01)
  0x91, 0x02,        //   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
  0x95, 0x01,        //   Report Count (1)
  0x09, 0x01,        //   Usage (0x01)
  0xb1, 0x02,        //   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
  0xc0,              // End Collection
};

const alignas(4) usb_string_descriptor_zero_t usb_string_descriptor_zero =
{
  .bLength               = sizeof(usb_string_descriptor_zero_t),
  .bDescriptorType       = USB_STRING_DESCRIPTOR,
  .wLANGID               = 0x0409, // English (United States)
};

char usb_serial_number[16];

const char *usb_strings[] =
{
  [USB_STR_MANUFACTURER]  = "Alex Taradov",
  [USB_STR_PRODUCT]       = "Combined VCP and CMSIS-DAP Adapter",
  [USB_STR_COM_PORT]      = "Virtual COM-Port",
  [USB_STR_CMSIS_DAP]     = "CMSIS-DAP Adapter",
  [USB_STR_SERIAL_NUMBER] = usb_serial_number,
};


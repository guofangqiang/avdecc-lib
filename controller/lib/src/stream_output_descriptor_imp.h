/*
 * Licensed under the MIT License (MIT)
 *
 * Copyright (c) 2013 AudioScience Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/**
 * stream_output_descriptor_imp.h
 *
 * Stream Output descriptor implementation class
 */

#pragma once
#ifndef _AVDECC_CONTROLLER_LIB_STREAM_OUTPUT_DESCRIPTOR_IMP_H_
#define _AVDECC_CONTROLLER_LIB_STREAM_OUTPUT_DESCRIPTOR_IMP_H_

#include "descriptor_base_imp.h"
#include "stream_output_descriptor.h"

#define IEC61883_AM824_MBLA_48KHZ_1CH UINT64_C(0x00a0020140000100)
#define IEC61883_AM824_MBLA_48KHZ_2CH UINT64_C(0x00a0020240000200)

namespace avdecc_lib
{
        class stream_output_descriptor_imp : public virtual stream_output_descriptor, public virtual descriptor_base_imp
        {
        private:
                struct jdksavdecc_descriptor_stream stream_output_desc; // Structure containing the stream_output_desc fields
                int stream_output_desc_read_returned; // Status of extracting Stream Output descriptor information from a network buffer

                struct stream_input_desc_stream_flags
                {
                        bool clock_sync_source;
                        bool class_a;
                        bool class_b;
                        bool supports_encrypted;
                        bool primary_backup_supported;
                        bool primary_backup_valid;
                        bool secondary_backup_supported;
                        bool secondary_backup_valid;
                        bool tertiary_backup_supported;
                        bool tertiary_back_up_valid;
                };

                struct stream_input_desc_stream_flags stream_flags;
                struct jdksavdecc_aem_command_get_stream_format_response aem_cmd_get_stream_format_resp;
                struct jdksavdecc_aem_command_get_stream_info_response aem_cmd_get_stream_info_resp;

        public:
                /**
                 * An empty constructor for stream_output_descriptor_imp
                 */
                stream_output_descriptor_imp();

                /**
                 * Constructor for stream_output_descriptor_imp used for constructing an object with a base End Station, frame, position offest,
                 * and memory buffer length.
                 */
                stream_output_descriptor_imp(end_station_imp *base_end_station_imp_ref, uint8_t *frame, size_t pos, size_t mem_buf_len);

                /**
                 * Destructor for stream_output_descriptor_imp used for destroying objects
                 */
                virtual ~stream_output_descriptor_imp();

                /**
                 * Get the descriptor type of the Stream Output descriptor object.
                 */
                uint16_t STDCALL get_descriptor_type();

                /**
                 * Get the descriptor index of the Stream Output descriptor object.
                 */
                uint16_t STDCALL get_descriptor_index();

                /**
                 * Get the name of the Stream Output descriptor object.
                 */
                uint8_t * STDCALL get_object_name();

                /**
                 * Get the localized description of the Stream Output descriptor object.
                 */
                uint16_t STDCALL get_localized_description();

                /**
                 * Get the Clock Domain index of the Stream Output descriptor object.
                 */
                uint16_t STDCALL get_clock_domain_index();

                /**
                 * Get the stream flags of the Stream Output descriptor object.
                 */
                uint16_t STDCALL get_stream_flags();

                /**
                * Get the current format of the Stream Output descriptor object.
                */
                char * STDCALL get_current_format();

                /**
                 * Get the formats offset of the Stream Output descriptor object.
                 */
                uint16_t STDCALL get_formats_offset();

                /**
                 * Get the number of formats of the Stream Output descriptor object.
                 */
                uint16_t STDCALL get_number_of_formats();

                /**
                 * Get the backup talker entity id 0 of the Stream Output descriptor object.
                 */
                uint64_t STDCALL get_backup_talker_entity_id_0();

                /**
                 * Get the backup talker unique_0 of the Stream Output descriptor object.
                 */
                uint16_t STDCALL get_backup_talker_unique_0();

                /**
                 * Get the backup talker entity id 1 of the Stream Output descriptor object.
                 */
                uint64_t STDCALL get_backup_talker_entity_id_1();

                /**
                 * Get the backup talker unique_1 of the Stream Output descriptor object.
                 */
                uint16_t STDCALL get_backup_talker_unique_1();

                /**
                 * Get the backup talker entity id 2 of the Stream Output descriptor object.
                 */
                uint64_t STDCALL get_backup_talker_entity_id_2();

                /**
                 * Get the backup talker unique 2 of the Stream Output descriptor object.
                 */
                uint16_t STDCALL get_backup_talker_unique_2();

                /**
                 * Get the backedup talker entity id of the Stream Output descriptor object.
                 */
                uint64_t STDCALL get_backedup_talker_entity_id();

                /**
                 * Get the backedup talker unique of the Stream Output descriptor object.
                 */
                uint16_t STDCALL get_backedup_talker_unique();

                /**
                 * Get the AVB Interface index of the Stream Output descriptor object.
                 */
                uint16_t STDCALL get_avb_interface_index();

                /**
                 * Get the buffer length of the Stream Output descriptor object.
                 */
                uint32_t STDCALL get_buffer_length();

                /**
                 * Get the stream format of a stream.
                 */
                uint64_t STDCALL get_stream_format_stream_format();

                /**
                 * Get the stream info flags of a stream.
                 */
                uint32_t STDCALL get_stream_info_flags();

                /**
                 * Get the stream info stream format of a stream.
                 */
                uint64_t STDCALL get_stream_info_stream_format();

                /**
                 * Get the stream info stream id of a stream.
                 */
                uint64_t STDCALL get_stream_info_stream_id();

                /**
                 * Get the stream info MSRP accumulated latency of a stream.
                 */
                uint32_t STDCALL get_stream_info_msrp_accumulated_latency();

                /**
                 * Get the stream info stream destination MAC of a stream.
                 */
                uint8_t * STDCALL get_stream_info_stream_dest_mac();

                /**
                 * Get the stream info MSRP failure code of a stream.
                 */
                uint8_t STDCALL get_stream_info_msrp_failure_code();

                /**
                 * Get the stream info MSRP failure bridge id of a stream.
                 */
                uint64_t STDCALL get_stream_info_msrp_failure_bridge_id();

                /**
                 * Check if the Clock Sync Source flag is set.
                 */
                bool is_clock_sync_source_set();

                /**
                 * Send a SET_STREAM_FORMAT command with or without a notifying id based on the notifying flag to change the format of a stream.
                 */
                int STDCALL send_set_stream_format_cmd(void *notification_id, uint16_t desc_index, uint64_t new_stream_format);

                /**
                 * Process a SET_STREAM_FORMAT response for the SET_STREAM_FORMAT command.
                 */
                int proc_set_stream_format_resp(void *notification_id, uint32_t &notification_flag, uint8_t *frame, uint16_t mem_buf_len);

                /**
                 * Send a GET_STREAM_FORMAT command with or without a notifying id based on the notifying flag to fetch the current format of a stream.
                 */
                int STDCALL send_get_stream_format_cmd(void *notification_id, uint16_t desc_index);

                /**
                 * Process a GET_STREAM_FORMAT response for the GET_STREAM_FORMAT command.
                 */
                int proc_get_stream_format_resp(void *notification_id, uint32_t &notification_flag, uint8_t *frame, uint16_t mem_buf_len);

                /**
                 * Send a SET_STREAM_INFO command with or without a notifying id based on the notifying flag to change the current values
                 * of the dynamic information of the stream.
                 */
                int STDCALL send_set_stream_info_cmd(void *notification_id, uint16_t desc_index, void *new_stream_info_field);

                /**
                 * Process a SET_STREAM_INFO response for the SET_STREAM_INFO command.
                 */
                int proc_set_stream_info_resp(void *notification_id, uint32_t &notification_flag, uint8_t *frame, uint16_t mem_buf_len);

                /**
                 * Send a GET_STREAM_INFO command with or without a notifying id based on the notifying flag to fetch the current information for a stream.
                 */
                int STDCALL send_get_stream_info_cmd(void *notification_id, uint16_t desc_index);

                /**
                 * Process a GET_STREAM_INFO response for the GET_STREAM_INFO command.
                 */
                int proc_get_stream_info_resp(void *notification_id, uint32_t &notification_flag, uint8_t *frame, uint16_t mem_buf_len);
        };
}

#endif
/*
 * Copyright (c) 2014-2018 Cesanta Software Limited
 * All rights reserved
 *
 * Licensed under the Apache License, Version 2.0 (the ""License"");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an ""AS IS"" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <stdbool.h>

#include "mgos_event.h"
#include "mgos_net.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Retrieve IP configuration of the provided instance number (which should be
 * of type `MGOS_NET_IF_TYPE_PPP`), and fill provided `ip_info` with it. Returns
 * `true` in case of success, false otherwise.
 */
bool mgos_pppos_dev_get_ip_info(int if_instance,
                                struct mgos_net_ip_info *ip_info);

#define MGOS_PPPOS_BASE MGOS_EVENT_BASE('P', 'o', 'S')

enum mgos_pppos_event {
  MGOS_PPPOS_CMD_RESP = MGOS_PPPOS_BASE,  // ev_data: struct mgos_pppos_cmd_resp
};

struct mgos_pppos_cmd_resp {
  int iface;
  struct mg_str request;
  struct mg_str response;
};

bool mgos_pppos_send_cmd(int iface, const char *req);

bool mgos_pppos_create(const struct mgos_config_pppos *cfg, int if_instance);

#ifdef __cplusplus
}
#endif

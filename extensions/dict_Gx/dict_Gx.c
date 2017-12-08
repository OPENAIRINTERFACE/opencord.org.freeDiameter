/*
* Copyright (c) 2017 Sprint
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*    http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

/****************
 Generated By: fdtool enhancements to diafuzzer
 License: same as freeDiameter
****************/


/* 
 * Dictionary definitions of objects specified in Gx (e30).
 */
#include <freeDiameter/extension.h>

#define PROTO_VER "e30"
#define GEN_DATE  1506697205.07

const char *gx_proto_ver = PROTO_VER;
const double gx_gen_date = GEN_DATE;

/* The content of this file follows the same structure as dict_base_proto.c */

#define CHECK_dict_new( _type, _data, _parent, _ref )                                     \
{                                                                                         \
    int _ret = fd_dict_new( fd_g_config->cnf_dict, (_type), (_data), (_parent), (_ref) ); \
    if ( _ret != 0 && _ret != EEXIST )                                                    \
       return _ret;                                                                       \
}

#define CHECK_dict_search( _type, _criteria, _what, _result )		\
    CHECK_FCT(  fd_dict_search( fd_g_config->cnf_dict, (_type), (_criteria), (_what), (_result), ENOENT) );

struct local_rules_definition {
    struct dict_avp_request avp_vendor_plus_name;
    enum rule_position	position;
    int 			min;
    int			max;
};

#define RULE_ORDER( _position ) ((((_position) == RULE_FIXED_HEAD) || ((_position) == RULE_FIXED_TAIL)) ? 1 : 0 )

/* Attention! This version of the macro uses AVP_BY_NAME_AND_VENDOR, in contrast to most other copies! */
#define PARSE_loc_rules( _rulearray, _parent) {                                                         \
        int __ar;                                                                                       \
        for (__ar=0; __ar < sizeof(_rulearray) / sizeof((_rulearray)[0]); __ar++) {                     \
                struct dict_rule_data __data = { NULL,                                                  \
                        (_rulearray)[__ar].position,                                                    \
                        0,                                                                              \
                        (_rulearray)[__ar].min,                                                         \
                        (_rulearray)[__ar].max};                                                        \
                __data.rule_order = RULE_ORDER(__data.rule_position);                                   \
                CHECK_FCT(  fd_dict_search(                                                             \
                        fd_g_config->cnf_dict,                                                          \
                        DICT_AVP,                                                                       \
                        AVP_BY_NAME_AND_VENDOR,                                                         \
                        &(_rulearray)[__ar].avp_vendor_plus_name,                                       \
                        &__data.rule_avp, 0 ) );                                                        \
                if ( !__data.rule_avp ) {                                                               \
                        TRACE_DEBUG(INFO, "AVP Not found: '%s'", (_rulearray)[__ar].avp_vendor_plus_name.avp_name);             \
                        return ENOENT;                                                                  \
                }                                                                                       \
                {                                                                                       \
                         int _ret = fd_dict_new( fd_g_config->cnf_dict, DICT_RULE, &(__data), (_parent), NULL ); \
                         if ( _ret != 0 && _ret != EEXIST )      {                                      \
                                TRACE_DEBUG(INFO, "Error on rule with AVP '%s'",                        \
                                            (_rulearray)[__ar].avp_vendor_plus_name.avp_name);          \
                                return EINVAL;                                                          \
                         }                                                                              \
                }                                                                                       \
        }                                                                                               \
}

#define CHECK_vendor_new( _data ) { \
        struct dict_object * vendor_found; \
        if (fd_dict_search(fd_g_config->cnf_dict,DICT_VENDOR,VENDOR_BY_ID,&_data.vendor_id,&vendor_found,ENOENT) == ENOENT) { \
                CHECK_FCT(fd_dict_new(fd_g_config->cnf_dict, DICT_VENDOR, &_data, NULL, NULL)); \
        } \
}

#define enumval_def_u32( _val_, _str_ )		\
    { _str_, 		{ .u32 = _val_ }}

#define enumval_def_os( _len_, _val_, _str_ )				\
    { _str_, 		{ .os = { .data = (unsigned char *)_val_, .len = _len_ }}}


static int dict_gx_load_defs(char * conffile)
{
   TRACE_ENTRY("%p", conffile);
	struct dict_object * app_id16777224;

	/* Application Section */
	{
	  {
			struct dict_object * vendor;
			CHECK_dict_search(DICT_VENDOR, VENDOR_BY_NAME, "3GPP", &vendor)
			struct dict_application_data data = { 16777224, "Gx" };
			CHECK_dict_new( DICT_APPLICATION, &data, vendor, &app_id16777224)
	  }
	  /* Result codes */
	  {
			struct dict_object *type;
			CHECK_dict_search(DICT_TYPE, TYPE_BY_NAME, "Enumerated(Result-Code)",&type);
			struct dict_enumval_data        t_1 = { "DIAMETER_USER_UNKNOWN", { .u32=5030 }};
			struct dict_enumval_data        t_2 = { "DIAMETER_ERROR_LATE_OVERLAPPING_REQUEST", { .u32=5453 }};
			struct dict_enumval_data        t_3 = { "DIAMETER_ERROR_TIMED_OUT_REQUEST", { .u32=5454 }};
			struct dict_enumval_data        t_4 = { "DIAMETER_ERROR_INITIAL_PARAMETERS", { .u32=5140 }};
			struct dict_enumval_data        t_5 = { "DIAMETER_ERROR_TRIGGER_EVENT", { .u32=5141 }};
			struct dict_enumval_data        t_6 = { "DIAMETER_PCC_RULE_EVENT", { .u32=5142 }};
			struct dict_enumval_data        t_7 = { "DIAMETER_ERROR_BEARER_NOT_AUTHORIZED", { .u32=5143 }};
			struct dict_enumval_data        t_8 = { "DIAMETER_ERROR_TRAFFIC_MAPPING_INFO_REJECTED", { .u32=5144 }};
			struct dict_enumval_data        t_9 = { "DIAMETER_ERROR_CONFLICTING_REQUEST", { .u32=5147 }};
			struct dict_enumval_data        t_10 = { "DIAMETER_ADC_RULE_EVENT", { .u32=5148 }};
			struct dict_enumval_data        t_11 = { "DIAMETER_ERROR_NBIFOM_NOT_AUTHORIZED", { .u32=5149 }};
			struct dict_enumval_data        t_12 = { "DIAMETER_PCC_BEARER_EVENT", { .u32=4141 }};
			struct dict_enumval_data        t_13 = { "DIAMETER_AN_GW_FAILED", { .u32=4143 }};
			struct dict_enumval_data        t_14 = { "DIAMETER_PENDING_TRANSACTION", { .u32=4144 }};

			CHECK_dict_new( DICT_ENUMVAL, &t_1, type, NULL);
			CHECK_dict_new( DICT_ENUMVAL, &t_2, type, NULL);
			CHECK_dict_new( DICT_ENUMVAL, &t_3, type, NULL);
			CHECK_dict_new( DICT_ENUMVAL, &t_4, type, NULL);
			CHECK_dict_new( DICT_ENUMVAL, &t_5, type, NULL);
			CHECK_dict_new( DICT_ENUMVAL, &t_6, type, NULL);
			CHECK_dict_new( DICT_ENUMVAL, &t_7, type, NULL);
			CHECK_dict_new( DICT_ENUMVAL, &t_8, type, NULL);
			CHECK_dict_new( DICT_ENUMVAL, &t_9, type, NULL);
			CHECK_dict_new( DICT_ENUMVAL, &t_10, type, NULL);
			CHECK_dict_new( DICT_ENUMVAL, &t_11, type, NULL);
			CHECK_dict_new( DICT_ENUMVAL, &t_12, type, NULL);
			CHECK_dict_new( DICT_ENUMVAL, &t_13, type, NULL);
			CHECK_dict_new( DICT_ENUMVAL, &t_14, type, NULL);

	  }
	}


   /* AVP section */
   {
		struct dict_object * Address_type;
		struct dict_object * UTF8String_type;
		struct dict_object * DiameterIdentity_type;
		struct dict_object * DiameterURI_type;
		struct dict_object * Time_type;
		struct dict_object * IPFilterRule_type;

		CHECK_dict_search( DICT_TYPE, TYPE_BY_NAME, "Address", &Address_type);
		CHECK_dict_search( DICT_TYPE, TYPE_BY_NAME, "UTF8String", &UTF8String_type);
		CHECK_dict_search( DICT_TYPE, TYPE_BY_NAME, "DiameterIdentity", &DiameterIdentity_type);
		CHECK_dict_search( DICT_TYPE, TYPE_BY_NAME, "DiameterURI", &DiameterURI_type);
		CHECK_dict_search( DICT_TYPE, TYPE_BY_NAME, "Time", &Time_type);
		CHECK_dict_search( DICT_TYPE, TYPE_BY_NAME, "IPFilterRule", &IPFilterRule_type);

	
   }

   /* Commands section */
   {

   }

   return 0;
}

static int dict_gx_load_rules(char * conffile)
{
   /* Grouped AVP section */
   {

   }	

   /* Commands section */
   {
	  /* Credit-Control-Request */
	  {
		struct dict_object* cmd;
		CHECK_dict_search( DICT_COMMAND, CMD_BY_NAME, "Credit-Control-Request", &cmd)
		struct local_rules_definition rules[] =
		{
			{ { .avp_vendor = 0, .avp_name = "Session-Id"}, RULE_FIXED_HEAD, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "DRMP"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Auth-Application-Id"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Host"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Realm"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Destination-Realm"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "CC-Request-Type"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "CC-Request-Number"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Credit-Management-Status"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Destination-Host"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-State-Id"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Subscription-Id"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "OC-Supported-Features"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Supported-Features"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "TDF-Information"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Network-Request-Support"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Packet-Filter-Information"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Packet-Filter-Operation"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Bearer-Identifier"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Bearer-Operation"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Dynamic-Address-Flag"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Dynamic-Address-Flag-Extension"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "PDN-Connection-Charging-ID"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Framed-IP-Address"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Framed-IPv6-Prefix"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "IP-CAN-Type"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "3GPP-RAT-Type"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "AN-Trusted"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "RAT-Type"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Termination-Cause"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "User-Equipment-Info"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "QoS-Information"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "QoS-Negotiation"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "QoS-Upgrade"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Default-EPS-Bearer-QoS"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Default-QoS-Information"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "AN-GW-Address"}, RULE_OPTIONAL, 0, 2 },
			{ { .avp_vendor = 10415, .avp_name = "AN-GW-Status"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "3GPP-SGSN-MCC-MNC"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "3GPP-SGSN-Address"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "3GPP-SGSN-Ipv6-Address"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "3GPP-GGSN-Address"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "3GPP-GGSN-Ipv6-Address"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "3GPP-Selection-Mode"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "RAI"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "3GPP-User-Location-Info"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Fixed-User-Location-Info"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "User-Location-Info-Time"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "User-CSG-Information"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "TWAN-Identifier"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "3GPP-MS-TimeZone"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "RAN-NAS-Release-Cause"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "3GPP-Charging-Characteristics"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Called-Station-Id"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "PDN-Connection-ID"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Bearer-Usage"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Online"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Offline"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "TFT-Packet-Filter-Information"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Charging-Rule-Report"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Application-Detection-Information"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Event-Trigger"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Event-Report-Indication"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Access-Network-Charging-Address"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Access-Network-Charging-Identifier-Gx"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "CoA-Information"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Usage-Monitoring-Information"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "NBIFOM-Support"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "NBIFOM-Mode"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Default-Access"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Origination-Time-Stamp"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Maximum-Wait-Time"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Access-Availability-Change-Reason"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Routing-Rule-Install"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Routing-Rule-Remove"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "HeNB-Local-IP-Address"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "UE-Local-IP-Address"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "UDP-Source-Port"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Presence-Reporting-Area-Information"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 13019, .avp_name = "Logical-Access-Id"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 13019, .avp_name = "Physical-Access-Id"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Proxy-Info"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Route-Record"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "3GPP-PS-Data-Off-Status"}, RULE_OPTIONAL, -1, -1 }
		};
		PARSE_loc_rules(rules, cmd);
	  }
	  /* Credit-Control-Answer */
	  {
		struct dict_object* cmd;
		CHECK_dict_search( DICT_COMMAND, CMD_BY_NAME, "Credit-Control-Answer", &cmd)
		struct local_rules_definition rules[] =
		{
			{ { .avp_vendor = 0, .avp_name = "Session-Id"}, RULE_FIXED_HEAD, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "DRMP"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Auth-Application-Id"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Host"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Realm"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Result-Code"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Experimental-Result"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "CC-Request-Type"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "CC-Request-Number"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "OC-Supported-Features"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "OC-OLR"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Supported-Features"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Bearer-Control-Mode"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Event-Trigger"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Event-Report-Indication"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-State-Id"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Redirect-Host"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Redirect-Host-Usage"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Redirect-Max-Cache-Time"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Charging-Rule-Remove"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Charging-Rule-Install"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Charging-Information"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Online"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Offline"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "QoS-Information"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Revalidation-Time"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Default-EPS-Bearer-QoS"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Default-QoS-Information"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Bearer-Usage"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Usage-Monitoring-Information"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "CSG-Information-Reporting"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "User-CSG-Information"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "PRA-Install"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "PRA-Remove"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Presence-Reporting-Area-Information"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Session-Release-Cause"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "NBIFOM-Support"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "NBIFOM-Mode"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Default-Access"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "RAN-Rule-Support"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Routing-Rule-Report"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Conditional-Policy-Information"}, RULE_OPTIONAL, 0, 4 },
			{ { .avp_vendor = 10415, .avp_name = "Removal-Of-Access"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "IP-CAN-Type"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Error-Message"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Error-Reporting-Host"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Failed-AVP"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Proxy-Info"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Route-Record"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Load"}, RULE_OPTIONAL, -1, -1 }
		};
		PARSE_loc_rules(rules, cmd);
	  }
	  /* Re-Auth-Request */
	  {
		struct dict_object* cmd;
		CHECK_dict_search( DICT_COMMAND, CMD_BY_NAME, "Re-Auth-Request", &cmd)
		struct local_rules_definition rules[] =
		{
			{ { .avp_vendor = 0, .avp_name = "Session-Id"}, RULE_FIXED_HEAD, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "DRMP"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Auth-Application-Id"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Host"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Realm"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Destination-Realm"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Destination-Host"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Re-Auth-Request-Type"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Session-Release-Cause"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-State-Id"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "OC-Supported-Features"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Event-Trigger"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Event-Report-Indication"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Charging-Rule-Remove"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Charging-Rule-Install"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Default-EPS-Bearer-QoS"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "QoS-Information"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Default-QoS-Information"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Revalidation-Time"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Usage-Monitoring-Information"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "PCSCF-Restoration-Indication"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Conditional-Policy-Information"}, RULE_OPTIONAL, 0, 4 },
			{ { .avp_vendor = 10415, .avp_name = "Removal-Of-Access"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "IP-CAN-Type"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "PRA-Install"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "PRA-Remove"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Proxy-Info"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Route-Record"}, RULE_OPTIONAL, -1, -1 }
		};
		PARSE_loc_rules(rules, cmd);
	  }
	  /* Re-Auth-Answer */
	  {
		struct dict_object* cmd;
		CHECK_dict_search( DICT_COMMAND, CMD_BY_NAME, "Re-Auth-Answer", &cmd)
		struct local_rules_definition rules[] =
		{
			{ { .avp_vendor = 0, .avp_name = "Session-Id"}, RULE_FIXED_HEAD, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "DRMP"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Host"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Realm"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Result-Code"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Experimental-Result"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-State-Id"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "OC-Supported-Features"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "OC-OLR"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "IP-CAN-Type"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "RAT-Type"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "AN-Trusted"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "AN-GW-Address"}, RULE_OPTIONAL, 0, 2 },
			{ { .avp_vendor = 10415, .avp_name = "3GPP-SGSN-MCC-MNC"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "3GPP-SGSN-Address"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "3GPP-SGSN-Ipv6-Address"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "RAI"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "3GPP-User-Location-Info"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "User-Location-Info-Time"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "NetLoc-Access-Support"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "User-CSG-Information"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "3GPP-MS-TimeZone"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Default-QoS-Information"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Charging-Rule-Report"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Error-Message"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Error-Reporting-Host"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Failed-AVP"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Proxy-Info"}, RULE_OPTIONAL, -1, -1 }
		};
		PARSE_loc_rules(rules, cmd);
	  }

   }

   LOG_D( "Extension 'Dictionary definitions for Gx (e30)' initialized");
   return 0;
}

int dict_entry(char * conffile)
{
	dict_gx_load_defs(conffile);
	return dict_gx_load_rules(conffile);
}

const char* dict_gx_proto_ver(char * conffile) {
	return gx_proto_ver;
}

const double dict_gx_gen_ts(char * conffile) {
	return gx_gen_date;
}

EXTENSION_ENTRY2("dict_gx", dict_gx_load_defs, dict_gx_load_rules, "dict_ts32299_avps", "dict_ts29212_avps", "dict_ts29273_avps", "dict_ts29214_avps", "dict_ts29272_avps", "dict_ts29229_avps", "dict_ts29061_avps", "dict_CreditControl", "dict_rfc4006bis_avps", "dict_draftload_avps", "dict_rfc7683_avps", "dict_rfc7155_avps", "dict_etsi283034_avps", "dict_3gpp2_avps", "dict_rfc7944_avps");



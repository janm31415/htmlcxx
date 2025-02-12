/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * This file is part of htmlcxx -- A simple non-validating css1 and html parser
 * written in C++.
 *
 * htmlcxx is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * Uri.h Licensed under the Apache License, Version 2.0 (the "License"); 
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing, software distributed 
 * under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR 
 * CONDITIONS OF ANY KIND, either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 * 
 * Copyright 2005-2010 Davi de Castro Reis and Robson Braga Araújo
 * Copyright 2011 David Hoerl
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef __HTMLCXX__URI_H__
#define __HTMLCXX__URI_H__

#include "_api.h"
#include <string>
#include <climits>
#include <stdexcept>

namespace htmlcxx
{
	class Uri
	{
		public:

			class Exception : public std::runtime_error
			{
				public:
					HTML_API Exception(const std::string &arg)
						: std::runtime_error(arg) {}
			};
			
			HTML_API Uri();
			HTML_API Uri(const std::string &uri);
			HTML_API ~Uri();

			HTML_API static std::string encode(const std::string &uri);
			HTML_API static std::string decode(const std::string &uri);

			HTML_API std::string unparse(int flags = 0) const;
			HTML_API Uri absolute(const Uri &base) const;

			HTML_API std::string canonicalHostname(unsigned int maxDepth = UINT_MAX) const;
			HTML_API unsigned int hostnameDepth() const;

			static const unsigned int URI_FTP_DEFAULT_PORT =          21 ; /**< default FTP port */
			static const unsigned int URI_SSH_DEFAULT_PORT =          22 ; /**< default SSH port */
			static const unsigned int URI_TELNET_DEFAULT_PORT =       23 ; /**< default telnet port */
			static const unsigned int URI_GOPHER_DEFAULT_PORT =       70 ; /**< default Gopher port */
			static const unsigned int URI_HTTP_DEFAULT_PORT =         80 ; /**< default HTTP port */
			static const unsigned int URI_POP_DEFAULT_PORT =         110 ; /**< default POP port */
			static const unsigned int URI_NNTP_DEFAULT_PORT =        119 ; /**< default NNTP port */
			static const unsigned int URI_IMAP_DEFAULT_PORT =        143 ; /**< default IMAP port */
			static const unsigned int URI_PROSPERO_DEFAULT_PORT =    191 ; /**< default Prospero port */
			static const unsigned int URI_WAIS_DEFAULT_PORT =        210 ; /**< default WAIS port */
			static const unsigned int URI_LDAP_DEFAULT_PORT =        389 ; /**< default LDAP port */
			static const unsigned int URI_HTTPS_DEFAULT_PORT =       443 ; /**< default HTTPS port */
			static const unsigned int URI_RTSP_DEFAULT_PORT =        554 ; /**< default RTSP port */
			static const unsigned int URI_SNEWS_DEFAULT_PORT =       563 ; /**< default SNEWS port */
			static const unsigned int URI_ACAP_DEFAULT_PORT =        674 ; /**< default ACAP port */
			static const unsigned int URI_NFS_DEFAULT_PORT =        2049 ; /**< default NFS port */
			static const unsigned int URI_TIP_DEFAULT_PORT =        3372 ; /**< default TIP port */
			static const unsigned int URI_SIP_DEFAULT_PORT =        5060 ; /**< default SIP port */

			const static int REMOVE_WWW_PREFIX = 1;
			const static int REMOVE_TRAILING_BAR = 2;
			const static int REMOVE_SCHEME = 8;
			const static int REMOVE_QUERY_VALUES = 16;
			const static int REMOVE_QUERY = 32;
			const static int REMOVE_DEFAULT_FILENAMES = 64;
			const static int REMOVE_FRAGMENT = 128;

			HTML_API std::string scheme() const;
			HTML_API void scheme(std::string scheme);
			HTML_API std::string user() const;
			HTML_API void user(std::string user);
			HTML_API std::string password() const;
			HTML_API void password(std::string password);
			HTML_API std::string hostname() const;
			HTML_API void hostname(std::string hostname);
			HTML_API std::string path() const;
			HTML_API void path(std::string path);
			HTML_API std::string query() const;
			HTML_API void query(std::string query);
			HTML_API std::string fragment() const;
			HTML_API void fragment(std::string fragment);
			HTML_API unsigned int port() const;
			HTML_API void port(unsigned int port);
			HTML_API bool existsFragment() const;
			HTML_API void existsFragment(bool existsFragment);
			HTML_API bool existsQuery() const;
			HTML_API void existsQuery(bool existsQuery);
		protected:
			void init(const std::string &uri_str);
			
			std::string mScheme;
			std::string mUser;
			std::string mPassword;
			std::string mHostname;
			std::string mPath;
			std::string mQuery;
			std::string mFragment;
			std::string mPortStr;;
			bool mExistsQuery;
			bool mExistsFragment;
			unsigned int mPort;
	};
}

#endif

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
 * htmlcxx is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with htmlcxx.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Copyright 2005-2010 Davi de Castro Reis and Robson Braga Araújo
 * Copyright 2011 David Hoerl
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef __HTML_PARSER_NODE_H
#define __HTML_PARSER_NODE_H

#include "_api.h"
#include <map>
#include <string>
#include <utility>

namespace htmlcxx {
	namespace HTML {
		class Node {

			public:
				HTML_API Node() {}
				//Node(const Node &rhs); //uses default
				HTML_API ~Node() {}

				HTML_API inline void text(const std::string& text) { this->mText = text; }
				HTML_API inline const std::string& text() const { return this->mText; }

				HTML_API inline unsigned int contentOffset() const { return this->mOffset + this->mText.length(); }
				HTML_API inline unsigned int contentLength() const { return this->mLength - this->mText.length() - this->mClosingText.length(); }
				HTML_API inline std::string content(const std::string& html) const { return html.substr(this->contentOffset(), this->contentLength()); }

				HTML_API inline void closingText(const std::string &text) { this->mClosingText = text; }
				HTML_API inline const std::string& closingText() const { return mClosingText; }

				HTML_API inline void offset(unsigned int offset) { this->mOffset = offset; }
				HTML_API inline unsigned int offset() const { return this->mOffset; }

				HTML_API inline void length(unsigned int length) { this->mLength = length; }
				HTML_API inline unsigned int length() const { return this->mLength; }

				HTML_API inline void tagName(const std::string& tagname) { this->mTagName = tagname; }
				HTML_API inline const std::string& tagName() const { return this->mTagName; }

				HTML_API bool isTag() const { return this->mIsHtmlTag; }
				HTML_API void isTag(bool is_html_tag){ this->mIsHtmlTag = is_html_tag; }

				HTML_API bool isComment() const { return this->mComment; }
				HTML_API void isComment(bool comment){ this->mComment = comment; }

				HTML_API std::pair<bool, std::string> attribute(const std::string &attr) const
				{ 
					std::map<std::string, std::string>::const_iterator i = this->mAttributes.find(attr);
					if (i != this->mAttributes.end()) {
						return make_pair(true, i->second);
					} else {
						return make_pair(false, std::string());
					}
				}

				HTML_API operator std::string() const;
				HTML_API std::ostream &operator<<(std::ostream &stream) const;

				HTML_API const std::map<std::string, std::string>& attributes() const { return this->mAttributes; }
				HTML_API void parseAttributes();

				HTML_API bool operator==(const Node &rhs) const;

			protected:

				std::string mText;
				std::string mClosingText;
				unsigned int mOffset;
				unsigned int mLength;
				std::string mTagName;
				std::map<std::string, std::string> mAttributes;
				bool mIsHtmlTag;
				bool mComment;
		};
	}
}

#endif

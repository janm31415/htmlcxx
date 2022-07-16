#ifndef __HTML_API_H__
#define __HTML_API_H__

#ifdef _WIN32
#if defined(html_EXPORTS)
#  define HTML_API __declspec(dllexport)
#else
#  define HTML_API __declspec(dllimport)
#endif
#else
#define HTML_API
#endif

#endif //__HTML_API_H__
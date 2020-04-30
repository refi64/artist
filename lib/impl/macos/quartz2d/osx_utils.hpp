/*=============================================================================
   Copyright (c) 2016-2020 Joel de Guzman

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#if !defined(ARTIST_DETAIL_OSX_UTILS_MARCH_17_2020)
#define ARTIST_DETAIL_OSX_UTILS_MARCH_17_2020

#include <Quartz/Quartz.h>
#include <string_view>

namespace cycfi::artist::detail
{
   inline CFStringRef cf_string(char const* f, char const* l)
   {
      return CFStringCreateWithBytesNoCopy(
         nullptr, (UInt8 const*)f, l-f, kCFStringEncodingUTF8
       , false, kCFAllocatorNull
      );
   }

   inline CFStringRef cf_string(std::string_view str)
   {
      return cf_string(str.data(), str.data()+str.size());
   }

   inline NSString* ns_string(char const* f, char const* l)
   {
      return (__bridge NSString*) cf_string(f, l);
   }

   inline NSString* ns_string(std::string_view str)
   {
      return ns_string(str.data(), str.data()+str.size());
   }
}

#endif

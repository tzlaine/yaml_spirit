/**
 *   Copyright (C) 2017 Zach Laine
 *
 *   Distributed under the Boost Software License, Version 1.0. (See accompanying
 *   file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef YAML_CONFIG_HPP
#define YAML_CONFIG_HPP


#ifndef YAML_HEADER_ONLY
#define YAML_HEADER_ONLY 0
#endif

#if YAML_HEADER_ONLY
#define YAML_HEADER_ONLY_INLINE inline
#else
#define YAML_HEADER_ONLY_INLINE
#endif

#ifndef YAML_NO_SPIRIT_DEBUGGING
#define BOOST_SPIRIT_DEBUG
#endif

#define BOOST_SPIRIT_NO_PREDEFINED_TERMINALS
#define BOOST_SPIRIT_ACTIONS_ALLOW_ATTR_COMPAT
#define BOOST_SPIRIT_UNICODE

#endif

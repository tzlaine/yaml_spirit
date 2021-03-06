/**
 *   Copyright (C) 2017 Zach Laine
 *
 *   Distributed under the Boost Software License, Version 1.0. (See accompanying
 *   file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef YAML_PARSER_BASIC_STRUCTURES_HPP
#define YAML_PARSER_BASIC_STRUCTURES_HPP

#include <yaml/parser/parser_fwd.hpp>
#include <yaml/parser/characters.hpp>


namespace yaml { namespace parser {

    struct basic_structures_t
    {
        explicit basic_structures_t (
            boost::phoenix::function<error_handler_t> const & error_handler,
            bool verbose
        );

        characters_t characters_;

        qi::rule<iterator_t, void(int)> indent;    // indent exactly n spaces
        qi::rule<iterator_t, void(int)> indent_lt; // indent <= n spaces
        qi::rule<iterator_t, void(int)> indent_le; // indent < n spaces
        qi::rule<iterator_t> separate_in_line;
        qi::rule<iterator_t, void(int, context_t)> line_prefix;
        qi::rule<iterator_t, char(int, context_t)> l_empty;
        qi::rule<iterator_t, std::string(int, context_t, bool stop_at_document_delimiter)> b_l_folded;
        qi::rule<iterator_t, std::string(int, bool stop_at_document_delimiter)> flow_folded;
        qi::rule<iterator_t> comment_text;
        qi::rule<iterator_t, void(eoi_state_t &)> s_b_comment;
        qi::rule<iterator_t, void(eoi_state_t &)> l_comment;
        qi::rule<iterator_t, void(eoi_state_t &)> s_l_comments;
        qi::rule<iterator_t, void(int, context_t)> separate;
        qi::rule<iterator_t, void(int), qi::locals<eoi_state_t>> separate_lines;

        qi::rule<iterator_t, qi::locals<eoi_state_t>> directive;
        qi::rule<iterator_t> reserved_directive;
        qi::rule<iterator_t, qi::locals<unsigned int>> yaml_directive;
        qi::rule<iterator_t> tag_directive;
        qi::rule<iterator_t> tag_handle;
        qi::rule<iterator_t> tag_prefix;

        qi::rule<
            iterator_t,
            ast::properties_t(int, context_t),
            qi::locals<iterator_range_t, iterator_range_t>
        > properties;

        qi::rule<iterator_t, iterator_range_t()> tag_property;
        qi::rule<iterator_t, iterator_range_t()> anchor_property;
        qi::rule<iterator_t, iterator_range_t()> anchor_name;

        qi::rule<iterator_t, void (eoi_state_t &)> one_time_eoi;

        std::reference_wrapper<boost::phoenix::function<error_handler_t> const> error_handler_;
    };

} }

#if YAML_HEADER_ONLY
#include <yaml/parser/basic_structures_def.hpp>
#endif

#endif

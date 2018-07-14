#include <boost/text/collation_search.hpp>

#include <gtest/gtest.h>


using namespace boost::text;


collation_table const default_table = default_collation_table();

// TODO: Other tables too!  This currently only uses the default one.
// TODO: Use non-ASCII CPs with tables that tailor those CPS.
// TODO: Use CPs associated with multiple CEs.

void do_simple_search(
    collation_table const & table,
    utf32_range str,
    utf32_range substr,
    int expected_first,
    int expected_last,
    int line)
{
    // TODO: Exercise the sentinel APIs.

    {
        auto const r = collation_search(str, substr, table);
        EXPECT_EQ(std::distance(str.begin(), r.begin()), expected_first)
            << "simple, line " << line;
        EXPECT_EQ(std::distance(str.begin(), r.end()), expected_last)
            << "simple, line " << line;
    }
    {
        auto r = collation_search(
            str, make_default_collation_searcher(substr, default_table));
        EXPECT_EQ(std::distance(str.begin(), r.begin()), expected_first)
            << "simple, line " << line;
        EXPECT_EQ(std::distance(str.begin(), r.end()), expected_last)
            << "simple, line " << line;
    }
}

void do_boyer_moore_search(
    collation_table const & table,
    utf32_range str,
    utf32_range substr,
    int expected_first,
    int expected_last,
    int line)
{
    // TODO: Exercise the searcher and non-searcher APIs.
    // TODO: Exercise the sentinel APIs.

    {
        auto r = collation_search(
            str, make_boyer_moore_collation_searcher(substr, default_table));
        EXPECT_EQ(std::distance(str.begin(), r.begin()), expected_first)
            << "BM, line " << line;
        EXPECT_EQ(std::distance(str.begin(), r.end()), expected_last)
            << "BM, line " << line;
    }
}

void do_boyer_moore_horspool_search(
    collation_table const & table,
    utf32_range str,
    utf32_range substr,
    int expected_first,
    int expected_last,
    int line)
{
    // TODO: Exercise the searcher and non-searcher APIs.
    // TODO: Exercise the sentinel APIs.

    {
        auto r = collation_search(
            str,
            make_boyer_moore_horspool_collation_searcher(
                substr, default_table));
        EXPECT_EQ(std::distance(str.begin(), r.begin()), expected_first)
            << "BMH, line " << line;
        EXPECT_EQ(std::distance(str.begin(), r.end()), expected_last)
            << "BMH, line " << line;
    }
}

void do_search(
    collation_table const & table,
    string const & str_,
    string const & substr_,
    int expected_first,
    int expected_last,
    int line)
{
    auto const str = utf32_range(str_);
    auto const substr = utf32_range(substr_);

    do_simple_search(table, str, substr, expected_first, expected_last, line);
    do_boyer_moore_search(
        table, str, substr, expected_first, expected_last, line);
    do_boyer_moore_horspool_search(
        table, str, substr, expected_first, expected_last, line);
}

// Test strings cribbed from Boost.Algorithm's search tests.  Thanks, Marshall!
TEST(collation_search, default_)
{
    string const haystack_1("NOW AN FOWE\220ER ANNMAN THE ANPANMANEND");
    string const needle_1("ANPANMAN");
    string const needle_2("MAN THE");
    string const needle_3("WE\220ER");
    string const needle_4("NOW ");
    string const needle_5("NEND");
    string const needle_6("NOT FOUND");
    string const needle_7("NOT FO\340ND");

    string const haystack_2("ABC ABCDAB ABCDABCDABDE");
    string const needle_11("ABCDABD");

    string const haystack_3("abra abracad abracadabra");
    string const needle_12("abracadabra");

    do_search(
        default_table,
        haystack_1,
        needle_1,
        26,
        26 + needle_1.size(),
        __LINE__);
    do_search(
        default_table,
        haystack_1,
        needle_2,
        18,
        18 + needle_2.size(),
        __LINE__);
    do_search(
        default_table, haystack_1, needle_3, 9, 9 + needle_3.size(), __LINE__);
    do_search(
        default_table, haystack_1, needle_4, 0, needle_4.size(), __LINE__);
    do_search(
        default_table,
        haystack_1,
        needle_5,
        33,
        33 + needle_5.size(),
        __LINE__);
    do_search(
        default_table,
        haystack_1,
        needle_6,
        haystack_1.size(),
        haystack_1.size(),
        __LINE__);
    do_search(
        default_table,
        haystack_1,
        needle_7,
        haystack_1.size(),
        haystack_1.size(),
        __LINE__);

    do_search(
        default_table,
        needle_1,
        haystack_1,
        needle_1.size(),
        needle_1.size(),
        __LINE__);
    do_search(
        default_table, haystack_1, haystack_1, 0, haystack_1.size(), __LINE__);
    do_search(
        default_table, haystack_2, haystack_2, 0, haystack_2.size(), __LINE__);

    do_search(
        default_table,
        haystack_2,
        needle_11,
        15,
        15 + needle_11.size(),
        __LINE__);
    do_search(
        default_table,
        haystack_3,
        needle_12,
        13,
        13 + needle_12.size(),
        __LINE__);

    do_search(default_table, haystack_1, "", 0, 0, __LINE__);
    do_search(default_table, "", needle_1, 0, 0, __LINE__);

    {
        string const base_pairs =
            "GATACACCTACCTTCACCAGTTACTCTATGCACTAGGTGCGCCAGGCCCATGCACAAGGGCTTGAG"
            "TGGATGGGAAGGATGTGCCCTAGTGATGGCAGCATAAGCTACGCAGAGAAGTTCCAGGGCAGAGTC"
            "ACCATGACCAGGGACACATCCACGAGCACAGCCTACATGGAGCTGAGCAGCCTGAGATCTGAAGAC"
            "ACGGCCATGTATTACTGTGGGAGAGATGTCTGGAGTGGTTATTATTGCCCCGGTAATATTACTACT"
            "ACTACTACTACATGGACGTCTGGGGCAAAGGGACCACG";
        string const corpus = repeat("a", 8) + base_pairs;

        do_search(
            default_table, corpus, base_pairs, 8, corpus.size(), __LINE__);
    }
}

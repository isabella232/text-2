#include <boost/text/string.hpp>


int main ()
{

{
//[ binary_slice_examples

    boost::text::string_view tv1 = "some text";

    boost::text::string_view tv2 = tv1(0, 4);
    assert(tv2 == "some");

    boost::text::string_view tv3 = tv1(-3, -1);
    assert(tv3 == "ex");
//]
    (void)tv2;
    (void)tv3;
}

{
//[ unary_slice_examples
    boost::text::string_view tv1 = "some text";

    boost::text::string_view tv2 = tv1(4);
    assert(tv2 == "some");

    boost::text::string_view tv3 = tv1(-4);
    assert(tv3 == "text");
//]
    (void)tv2;
    (void)tv3;
}

}

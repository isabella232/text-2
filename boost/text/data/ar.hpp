// Warning! This file is autogenerated.
#ifndef BOOST_TEXT_DATA_AR_HPP
#define BOOST_TEXT_DATA_AR_HPP

#include <boost/text/string_view.hpp>


namespace boost { namespace text { namespace data { namespace ar {

inline string_view compat_collation_tailoring()
{
    return string_view(
"  \n"
"[reorder Arab]\n"
"&\xd8\xaa<<\xd8\xa9<<<\xef\xba\x94<<<\xef\xba\x93\n"
"&\xd9\x8a<<\xd9\x89<<<\xef\xaf\xa8<<<\xef\xaf\xa9<<<\xef\xbb\xb0<<<\xef\xbb\xaf<<<\xef\xb2\x90<<<\xef\xb1\x9d\n"
"  \n");
}

inline string_view standard_collation_tailoring()
{
    return string_view(
"  \n"
"[reorder Arab]\n"
"&[before 2]\xd8\xaa<<\xe2\x80\x8e\xd8\xa9\n"
"&[before 2]\xe2\x80\x8e\xd9\x8a\xe2\x80\x8e<<\xdb\x8c<<\xe2\x80\x8e\xd9\x89\n"
"&\xe2\x80\x8e\xd8\xa1<<\xe2\x80\x8e\xd8\xa3<<\xe2\x80\x8e\xd8\xa4<<\xe2\x80\x8e\xd8\xa5<<\xe2\x80\x8e\xd8\xa6<<\xe2\x80\x8e\xd9\x89\xd9\x95<<\xe2\x80\x8e\xd8\xa7\n"
"  \xe2\x80\x8e&\xd8\xa1\xd8\xa7\xe2\x80\x8e<<\xe2\x80\x8e\xd8\xa2\xe2\x80\x8e\n"
"&[last secondary ignorable]<<<\\u064B<<<\\u08F0<<<\\u08E7<<<\\u064C<<<\\u08F1\n"
"  <<<\\u08E8<<<\\u064D<<<\\u08F2<<<\\u08E9<<<\\u064E<<<\\u08E4<<<\\u08F4<<<\\u08F5\n"
"  <<<\\u064F<<<\\u08E5<<<\\u08FE<<<\\u0650<<<\\u08E6<<<\\u08F6<<<\\u0651<<<\\u0652\n"
"  <<<\\u0653<<<\\u06DF<<<\\u06E1<<<\\u065F<<<\\u0656<<<\\u0657<<<\\u0658<<<\\u08FF\n"
"  <<<\\u0659<<<\\u065A<<<\\u065B<<<\\u065C<<<\\u065D<<<\\u065E<<<\\u08F7<<<\\u08F8\n"
"  <<<\\u08FD<<<\\u08FB<<<\\u08FC<<<\\u08F9<<<\\u08FA<<<\\u0670\n"
"&\xe2\x80\x8e'\xd8\xa8\xd8\xb3\xd9\x85 \xd8\xa7\xd9\x84\xd9\x84\xd9\x87 \xd8\xa7\xd9\x84\xd8\xb1\xd8\xad\xd9\x85\xd9\x86 \xd8\xa7\xd9\x84\xd8\xb1\xd8\xad\xd9\x8a\xd9\x85'<<<\xe2\x80\x8e\xef\xb7\xbd\n"
"  \xe2\x80\x8e&\xd8\xa1\xe2\x80\x8e=\xef\xba\x80\n"
"  \xe2\x80\x8e&\xd8\xa7\xe2\x80\x8e=\xef\xba\x8d\xe2\x80\x8e=\xef\xba\x8e\n"
"  \xe2\x80\x8e&\xd8\xa7\xd9\x83\xd8\xa8\xd8\xb1\xe2\x80\x8e<<<\xef\xb7\xb3\n"
"  \xe2\x80\x8e&\xd8\xa7\xd9\x84\xd9\x84\xd9\x87\xe2\x80\x8e<<<\xef\xb7\xb2\n"
"  \xe2\x80\x8e&\xd8\xa7\\u064B\xe2\x80\x8e=\xef\xb4\xbc\xe2\x80\x8e=\xef\xb4\xbd\n"
"  \xe2\x80\x8e&\xd8\xa2\xe2\x80\x8e=\xef\xba\x81\xe2\x80\x8e=\xef\xba\x82\n"
"  \xe2\x80\x8e&\xd8\xa3\xe2\x80\x8e=\xef\xba\x83\xe2\x80\x8e=\xef\xba\x84\n"
"  \xe2\x80\x8e&\xd8\xa5\xe2\x80\x8e=\xef\xba\x87\xe2\x80\x8e=\xef\xba\x88\n"
"  \xe2\x80\x8e&\xd8\xa8\xe2\x80\x8e=\xef\xba\x8f\xe2\x80\x8e=\xef\xba\x90\xe2\x80\x8e=\xef\xba\x91\xe2\x80\x8e=\xef\xba\x92\n"
"  \xe2\x80\x8e&\xd8\xa8\xd8\xac\xe2\x80\x8e=\xef\xb0\x85\xe2\x80\x8e=\xef\xb2\x9c\n"
"  \xe2\x80\x8e&\xd8\xa8\xd8\xad\xe2\x80\x8e=\xef\xb0\x86\xe2\x80\x8e=\xef\xb2\x9d\n"
"  \xe2\x80\x8e&\xd8\xa8\xd8\xad\xd9\x8a\xe2\x80\x8e=\xef\xb7\x82\n"
"  \xe2\x80\x8e&\xd8\xa8\xd8\xae\xe2\x80\x8e=\xef\xb0\x87\xe2\x80\x8e=\xef\xb2\x9e\n"
"  \xe2\x80\x8e&\xd8\xa8\xd8\xae\xd9\x8a\xe2\x80\x8e=\xef\xb6\x9e\n"
"  \xe2\x80\x8e&\xd8\xa8\xd8\xb1\xe2\x80\x8e=\xef\xb1\xaa\n"
"  \xe2\x80\x8e&\xd8\xa8\xd8\xb2\xe2\x80\x8e=\xef\xb1\xab\n"
"  \xe2\x80\x8e&\xd8\xa8\xd9\x85\xe2\x80\x8e=\xef\xb0\x88\xe2\x80\x8e=\xef\xb1\xac\xe2\x80\x8e=\xef\xb2\x9f\xe2\x80\x8e=\xef\xb3\xa1\n"
"  \xe2\x80\x8e&\xd8\xa8\xd9\x86\xe2\x80\x8e=\xef\xb1\xad\n"
"  \xe2\x80\x8e&\xd8\xa8\xd9\x87\xe2\x80\x8e=\xef\xb2\xa0\xe2\x80\x8e=\xef\xb3\xa2\n"
"  \xe2\x80\x8e&\xd8\xa8\xd9\x89\xe2\x80\x8e=\xef\xb0\x89\xe2\x80\x8e=\xef\xb1\xae\n"
"  \xe2\x80\x8e&\xd8\xa8\xd9\x8a\xe2\x80\x8e=\xef\xb0\x8a\xe2\x80\x8e=\xef\xb1\xaf\n"
"  \xe2\x80\x8e&\xd8\xa9\xe2\x80\x8e=\xef\xba\x93\xe2\x80\x8e=\xef\xba\x94\n"
"  \xe2\x80\x8e&\xd8\xaa\xe2\x80\x8e=\xef\xba\x95\xe2\x80\x8e=\xef\xba\x96\xe2\x80\x8e=\xef\xba\x97\xe2\x80\x8e=\xef\xba\x98\n"
"  \xe2\x80\x8e&\xd8\xaa\xd8\xac\xe2\x80\x8e=\xef\xb0\x8b\xe2\x80\x8e=\xef\xb2\xa1\n"
"  \xe2\x80\x8e&\xd8\xaa\xd8\xac\xd9\x85\xe2\x80\x8e=\xef\xb5\x90\n"
"  \xe2\x80\x8e&\xd8\xaa\xd8\xac\xd9\x89\xe2\x80\x8e=\xef\xb6\xa0\n"
"  \xe2\x80\x8e&\xd8\xaa\xd8\xac\xd9\x8a\xe2\x80\x8e=\xef\xb6\x9f\n"
"  \xe2\x80\x8e&\xd8\xaa\xd8\xad\xe2\x80\x8e=\xef\xb0\x8c\xe2\x80\x8e=\xef\xb2\xa2\n"
"  \xe2\x80\x8e&\xd8\xaa\xd8\xad\xd8\xac\xe2\x80\x8e=\xef\xb5\x91\xe2\x80\x8e=\xef\xb5\x92\n"
"  \xe2\x80\x8e&\xd8\xaa\xd8\xad\xd9\x85\xe2\x80\x8e=\xef\xb5\x93\n"
"  \xe2\x80\x8e&\xd8\xaa\xd8\xae\xe2\x80\x8e=\xef\xb0\x8d\xe2\x80\x8e=\xef\xb2\xa3\n"
"  \xe2\x80\x8e&\xd8\xaa\xd8\xae\xd9\x85\xe2\x80\x8e=\xef\xb5\x94\n"
"  \xe2\x80\x8e&\xd8\xaa\xd8\xae\xd9\x89\xe2\x80\x8e=\xef\xb6\xa2\n"
"  \xe2\x80\x8e&\xd8\xaa\xd8\xae\xd9\x8a\xe2\x80\x8e=\xef\xb6\xa1\n"
"  \xe2\x80\x8e&\xd8\xaa\xd8\xb1\xe2\x80\x8e=\xef\xb1\xb0\n"
"  \xe2\x80\x8e&\xd8\xaa\xd8\xb2\xe2\x80\x8e=\xef\xb1\xb1\n"
"  \xe2\x80\x8e&\xd8\xaa\xd9\x85\xe2\x80\x8e=\xef\xb0\x8e\xe2\x80\x8e=\xef\xb1\xb2\xe2\x80\x8e=\xef\xb2\xa4\xe2\x80\x8e=\xef\xb3\xa3\n"
"  \xe2\x80\x8e&\xd8\xaa\xd9\x85\xd8\xac\xe2\x80\x8e=\xef\xb5\x95\n"
"  \xe2\x80\x8e&\xd8\xaa\xd9\x85\xd8\xad\xe2\x80\x8e=\xef\xb5\x96\n"
"  \xe2\x80\x8e&\xd8\xaa\xd9\x85\xd8\xae\xe2\x80\x8e=\xef\xb5\x97\n"
"  \xe2\x80\x8e&\xd8\xaa\xd9\x85\xd9\x89\xe2\x80\x8e=\xef\xb6\xa4\n"
"  \xe2\x80\x8e&\xd8\xaa\xd9\x85\xd9\x8a\xe2\x80\x8e=\xef\xb6\xa3\n"
"  \xe2\x80\x8e&\xd8\xaa\xd9\x86\xe2\x80\x8e=\xef\xb1\xb3\n"
"  \xe2\x80\x8e&\xd8\xaa\xd9\x87\xe2\x80\x8e=\xef\xb2\xa5\xe2\x80\x8e=\xef\xb3\xa4\n"
"  \xe2\x80\x8e&\xd8\xaa\xd9\x89\xe2\x80\x8e=\xef\xb0\x8f\xe2\x80\x8e=\xef\xb1\xb4\n"
"  \xe2\x80\x8e&\xd8\xaa\xd9\x8a\xe2\x80\x8e=\xef\xb0\x90\xe2\x80\x8e=\xef\xb1\xb5\n"
"  \xe2\x80\x8e&\xd8\xab\xe2\x80\x8e=\xef\xba\x99\xe2\x80\x8e=\xef\xba\x9a\xe2\x80\x8e=\xef\xba\x9b\xe2\x80\x8e=\xef\xba\x9c\n"
"  \xe2\x80\x8e&\xd8\xab\xd8\xac\xe2\x80\x8e=\xef\xb0\x91\n"
"  \xe2\x80\x8e&\xd8\xab\xd8\xb1\xe2\x80\x8e=\xef\xb1\xb6\n"
"  \xe2\x80\x8e&\xd8\xab\xd8\xb2\xe2\x80\x8e=\xef\xb1\xb7\n"
"  \xe2\x80\x8e&\xd8\xab\xd9\x85\xe2\x80\x8e=\xef\xb0\x92\xe2\x80\x8e=\xef\xb1\xb8\xe2\x80\x8e=\xef\xb2\xa6\xe2\x80\x8e=\xef\xb3\xa5\n"
"  \xe2\x80\x8e&\xd8\xab\xd9\x86\xe2\x80\x8e=\xef\xb1\xb9\n"
"  \xe2\x80\x8e&\xd8\xab\xd9\x87\xe2\x80\x8e=\xef\xb3\xa6\n"
"  \xe2\x80\x8e&\xd8\xab\xd9\x89\xe2\x80\x8e=\xef\xb0\x93\xe2\x80\x8e=\xef\xb1\xba\n"
"  \xe2\x80\x8e&\xd8\xab\xd9\x8a\xe2\x80\x8e=\xef\xb0\x94\xe2\x80\x8e=\xef\xb1\xbb\n"
"  \xe2\x80\x8e&\xd8\xac\xe2\x80\x8e=\xef\xba\x9d\xe2\x80\x8e=\xef\xba\x9e\xe2\x80\x8e=\xef\xba\x9f\xe2\x80\x8e=\xef\xba\xa0\n"
"  \xe2\x80\x8e&\xd8\xac\xd8\xad\xe2\x80\x8e=\xef\xb0\x95\xe2\x80\x8e=\xef\xb2\xa7\n"
"  \xe2\x80\x8e&\xd8\xac\xd8\xad\xd9\x89\xe2\x80\x8e=\xef\xb6\xa6\n"
"  \xe2\x80\x8e&\xd8\xac\xd8\xad\xd9\x8a\xe2\x80\x8e=\xef\xb6\xbe\n"
"  \xe2\x80\x8e&'\xd8\xac\xd9\x84 \xd8\xac\xd9\x84\xd8\xa7\xd9\x84\xd9\x87'\xe2\x80\x8e<<<\xef\xb7\xbb\n"
"  \xe2\x80\x8e&\xd8\xac\xd9\x85\xe2\x80\x8e=\xef\xb0\x96\xe2\x80\x8e=\xef\xb2\xa8\n"
"  \xe2\x80\x8e&\xd8\xac\xd9\x85\xd8\xad\xe2\x80\x8e=\xef\xb5\x98\xe2\x80\x8e=\xef\xb5\x99\n"
"  \xe2\x80\x8e&\xd8\xac\xd9\x85\xd9\x89\xe2\x80\x8e=\xef\xb6\xa7\n"
"  \xe2\x80\x8e&\xd8\xac\xd9\x85\xd9\x8a\xe2\x80\x8e=\xef\xb6\xa5\n"
"  \xe2\x80\x8e&\xd8\xac\xd9\x89\xe2\x80\x8e=\xef\xb4\x81\xe2\x80\x8e=\xef\xb4\x9d\n"
"  \xe2\x80\x8e&\xd8\xac\xd9\x8a\xe2\x80\x8e=\xef\xb4\x82\xe2\x80\x8e=\xef\xb4\x9e\n"
"  \xe2\x80\x8e&\xd8\xad\xe2\x80\x8e=\xef\xba\xa1\xe2\x80\x8e=\xef\xba\xa2\xe2\x80\x8e=\xef\xba\xa3\xe2\x80\x8e=\xef\xba\xa4\n"
"  \xe2\x80\x8e&\xd8\xad\xd8\xac\xe2\x80\x8e=\xef\xb0\x97\xe2\x80\x8e=\xef\xb2\xa9\n"
"  \xe2\x80\x8e&\xd8\xad\xd8\xac\xd9\x8a\xe2\x80\x8e=\xef\xb6\xbf\n"
"  \xe2\x80\x8e&\xd8\xad\xd9\x85\xe2\x80\x8e=\xef\xb0\x98\xe2\x80\x8e=\xef\xb2\xaa\n"
"  \xe2\x80\x8e&\xd8\xad\xd9\x85\xd9\x89\xe2\x80\x8e=\xef\xb5\x9b\n"
"  \xe2\x80\x8e&\xd8\xad\xd9\x85\xd9\x8a\xe2\x80\x8e=\xef\xb5\x9a\n"
"  \xe2\x80\x8e&\xd8\xad\xd9\x89\xe2\x80\x8e=\xef\xb3\xbf\xe2\x80\x8e=\xef\xb4\x9b\n"
"  \xe2\x80\x8e&\xd8\xad\xd9\x8a\xe2\x80\x8e=\xef\xb4\x80\xe2\x80\x8e=\xef\xb4\x9c\n"
"  \xe2\x80\x8e&\xd8\xae\xe2\x80\x8e=\xef\xba\xa5\xe2\x80\x8e=\xef\xba\xa6\xe2\x80\x8e=\xef\xba\xa7\xe2\x80\x8e=\xef\xba\xa8\n"
"  \xe2\x80\x8e&\xd8\xae\xd8\xac\xe2\x80\x8e=\xef\xb0\x99\xe2\x80\x8e=\xef\xb2\xab\n"
"  \xe2\x80\x8e&\xd8\xae\xd8\xad\xe2\x80\x8e=\xef\xb0\x9a\n"
"  \xe2\x80\x8e&\xd8\xae\xd9\x85\xe2\x80\x8e=\xef\xb0\x9b\xe2\x80\x8e=\xef\xb2\xac\n"
"  \xe2\x80\x8e&\xd8\xae\xd9\x89\xe2\x80\x8e=\xef\xb4\x83\xe2\x80\x8e=\xef\xb4\x9f\n"
"  \xe2\x80\x8e&\xd8\xae\xd9\x8a\xe2\x80\x8e=\xef\xb4\x84\xe2\x80\x8e=\xef\xb4\xa0\n"
"  \xe2\x80\x8e&\xd8\xaf\xe2\x80\x8e=\xef\xba\xa9\xe2\x80\x8e=\xef\xba\xaa\n"
"  \xe2\x80\x8e&\xd8\xb0\xe2\x80\x8e=\xef\xba\xab\xe2\x80\x8e=\xef\xba\xac\n"
"  \xe2\x80\x8e&\xd8\xb0\\u0670\xe2\x80\x8e=\xef\xb1\x9b\n"
"  \xe2\x80\x8e&\xd8\xb1\xe2\x80\x8e=\xef\xba\xad\xe2\x80\x8e=\xef\xba\xae\n"
"  \xe2\x80\x8e&\xd8\xb1\xd8\xb3\xd9\x88\xd9\x84\xe2\x80\x8e<<<\xef\xb7\xb6\n"
"  \xe2\x80\x8e&\xd8\xb1\\u0670\xe2\x80\x8e=\xef\xb1\x9c\n"
"  \xe2\x80\x8e&\xd8\xb1\xdb\x8c\xd8\xa7\xd9\x84\xe2\x80\x8e<<<\xef\xb7\xbc\n"
"  \xe2\x80\x8e&\xd8\xb2\xe2\x80\x8e=\xef\xba\xaf\xe2\x80\x8e=\xef\xba\xb0\n"
"  \xe2\x80\x8e&\xd8\xb3\xe2\x80\x8e=\xef\xba\xb1\xe2\x80\x8e=\xef\xba\xb2\xe2\x80\x8e=\xef\xba\xb3\xe2\x80\x8e=\xef\xba\xb4\n"
"  \xe2\x80\x8e&\xd8\xb3\xd8\xac\xe2\x80\x8e=\xef\xb0\x9c\xe2\x80\x8e=\xef\xb2\xad\xe2\x80\x8e=\xef\xb4\xb4\n"
"  \xe2\x80\x8e&\xd8\xb3\xd8\xac\xd8\xad\xe2\x80\x8e=\xef\xb5\x9d\n"
"  \xe2\x80\x8e&\xd8\xb3\xd8\xac\xd9\x89\xe2\x80\x8e=\xef\xb5\x9e\n"
"  \xe2\x80\x8e&\xd8\xb3\xd8\xad\xe2\x80\x8e=\xef\xb0\x9d\xe2\x80\x8e=\xef\xb2\xae\xe2\x80\x8e=\xef\xb4\xb5\n"
"  \xe2\x80\x8e&\xd8\xb3\xd8\xad\xd8\xac\xe2\x80\x8e=\xef\xb5\x9c\n"
"  \xe2\x80\x8e&\xd8\xb3\xd8\xae\xe2\x80\x8e=\xef\xb0\x9e\xe2\x80\x8e=\xef\xb2\xaf\xe2\x80\x8e=\xef\xb4\xb6\n"
"  \xe2\x80\x8e&\xd8\xb3\xd8\xae\xd9\x89\xe2\x80\x8e=\xef\xb6\xa8\n"
"  \xe2\x80\x8e&\xd8\xb3\xd8\xae\xd9\x8a\xe2\x80\x8e=\xef\xb7\x86\n"
"  \xe2\x80\x8e&\xd8\xb3\xd8\xb1\xe2\x80\x8e=\xef\xb4\x8e\xe2\x80\x8e=\xef\xb4\xaa\n"
"  \xe2\x80\x8e&\xd8\xb3\xd9\x85\xe2\x80\x8e=\xef\xb0\x9f\xe2\x80\x8e=\xef\xb2\xb0\xe2\x80\x8e=\xef\xb3\xa7\n"
"  \xe2\x80\x8e&\xd8\xb3\xd9\x85\xd8\xac\xe2\x80\x8e=\xef\xb5\xa1\n"
"  \xe2\x80\x8e&\xd8\xb3\xd9\x85\xd8\xad\xe2\x80\x8e=\xef\xb5\x9f\xe2\x80\x8e=\xef\xb5\xa0\n"
"  \xe2\x80\x8e&\xd8\xb3\xd9\x85\xd9\x85\xe2\x80\x8e=\xef\xb5\xa2\xe2\x80\x8e=\xef\xb5\xa3\n"
"  \xe2\x80\x8e&\xd8\xb3\xd9\x87\xe2\x80\x8e=\xef\xb3\xa8\xe2\x80\x8e=\xef\xb4\xb1\n"
"  \xe2\x80\x8e&\xd8\xb3\xd9\x89\xe2\x80\x8e=\xef\xb3\xbb\xe2\x80\x8e=\xef\xb4\x97\n"
"  \xe2\x80\x8e&\xd8\xb3\xd9\x8a\xe2\x80\x8e=\xef\xb3\xbc\xe2\x80\x8e=\xef\xb4\x98\n"
"  \xe2\x80\x8e&\xd8\xb4\xe2\x80\x8e=\xef\xba\xb5\xe2\x80\x8e=\xef\xba\xb6\xe2\x80\x8e=\xef\xba\xb7\xe2\x80\x8e=\xef\xba\xb8\n"
"  \xe2\x80\x8e&\xd8\xb4\xd8\xac\xe2\x80\x8e=\xef\xb4\x89\xe2\x80\x8e=\xef\xb4\xa5\xe2\x80\x8e=\xef\xb4\xad\xe2\x80\x8e=\xef\xb4\xb7\n"
"  \xe2\x80\x8e&\xd8\xb4\xd8\xac\xd9\x8a\xe2\x80\x8e=\xef\xb5\xa9\n"
"  \xe2\x80\x8e&\xd8\xb4\xd8\xad\xe2\x80\x8e=\xef\xb4\x8a\xe2\x80\x8e=\xef\xb4\xa6\xe2\x80\x8e=\xef\xb4\xae\xe2\x80\x8e=\xef\xb4\xb8\n"
"  \xe2\x80\x8e&\xd8\xb4\xd8\xad\xd9\x85\xe2\x80\x8e=\xef\xb5\xa7\xe2\x80\x8e=\xef\xb5\xa8\n"
"  \xe2\x80\x8e&\xd8\xb4\xd8\xad\xd9\x8a\xe2\x80\x8e=\xef\xb6\xaa\n"
"  \xe2\x80\x8e&\xd8\xb4\xd8\xae\xe2\x80\x8e=\xef\xb4\x8b\xe2\x80\x8e=\xef\xb4\xa7\xe2\x80\x8e=\xef\xb4\xaf\xe2\x80\x8e=\xef\xb4\xb9\n"
"  \xe2\x80\x8e&\xd8\xb4\xd8\xb1\xe2\x80\x8e=\xef\xb4\x8d\xe2\x80\x8e=\xef\xb4\xa9\n"
"  \xe2\x80\x8e&\xd8\xb4\xd9\x85\xe2\x80\x8e=\xef\xb3\xa9\xe2\x80\x8e=\xef\xb4\x8c\xe2\x80\x8e=\xef\xb4\xa8\xe2\x80\x8e=\xef\xb4\xb0\n"
"  \xe2\x80\x8e&\xd8\xb4\xd9\x85\xd8\xae\xe2\x80\x8e=\xef\xb5\xaa\xe2\x80\x8e=\xef\xb5\xab\n"
"  \xe2\x80\x8e&\xd8\xb4\xd9\x85\xd9\x85\xe2\x80\x8e=\xef\xb5\xac\xe2\x80\x8e=\xef\xb5\xad\n"
"  \xe2\x80\x8e&\xd8\xb4\xd9\x87\xe2\x80\x8e=\xef\xb3\xaa\xe2\x80\x8e=\xef\xb4\xb2\n"
"  \xe2\x80\x8e&\xd8\xb4\xd9\x89\xe2\x80\x8e=\xef\xb3\xbd\xe2\x80\x8e=\xef\xb4\x99\n"
"  \xe2\x80\x8e&\xd8\xb4\xd9\x8a\xe2\x80\x8e=\xef\xb3\xbe\xe2\x80\x8e=\xef\xb4\x9a\n"
"  \xe2\x80\x8e&\xd8\xb5\xe2\x80\x8e=\xef\xba\xb9\xe2\x80\x8e=\xef\xba\xba\xe2\x80\x8e=\xef\xba\xbb\xe2\x80\x8e=\xef\xba\xbc\n"
"  \xe2\x80\x8e&\xd8\xb5\xd8\xad\xe2\x80\x8e=\xef\xb0\xa0\xe2\x80\x8e=\xef\xb2\xb1\n"
"  \xe2\x80\x8e&\xd8\xb5\xd8\xad\xd8\xad\xe2\x80\x8e=\xef\xb5\xa4\xe2\x80\x8e=\xef\xb5\xa5\n"
"  \xe2\x80\x8e&\xd8\xb5\xd8\xad\xd9\x8a\xe2\x80\x8e=\xef\xb6\xa9\n"
"  \xe2\x80\x8e&\xd8\xb5\xd8\xae\xe2\x80\x8e=\xef\xb2\xb2\n"
"  \xe2\x80\x8e&\xd8\xb5\xd8\xb1\xe2\x80\x8e=\xef\xb4\x8f\xe2\x80\x8e=\xef\xb4\xab\n"
"  \xe2\x80\x8e&\xd8\xb5\xd9\x84\xd8\xb9\xd9\x85\xe2\x80\x8e<<<\xef\xb7\xb5\n"
"  \xe2\x80\x8e&\xd8\xb5\xd9\x84\xd9\x89\xe2\x80\x8e<<<\xef\xb7\xb9\n"
"  \xe2\x80\x8e&'\xd8\xb5\xd9\x84\xd9\x89 \xd8\xa7\xd9\x84\xd9\x84\xd9\x87 \xd8\xb9\xd9\x84\xd9\x8a\xd9\x87 \xd9\x88\xd8\xb3\xd9\x84\xd9\x85'\xe2\x80\x8e<<<\xef\xb7\xba\n"
"  \xe2\x80\x8e&\xd8\xb5\xd9\x84\xdb\x92\xe2\x80\x8e<<<\xef\xb7\xb0\n"
"  \xe2\x80\x8e&\xd8\xb5\xd9\x85\xe2\x80\x8e=\xef\xb0\xa1\xe2\x80\x8e=\xef\xb2\xb3\n"
"  \xe2\x80\x8e&\xd8\xb5\xd9\x85\xd9\x85\xe2\x80\x8e=\xef\xb5\xa6\xe2\x80\x8e=\xef\xb7\x85\n"
"  \xe2\x80\x8e&\xd8\xb5\xd9\x89\xe2\x80\x8e=\xef\xb4\x85\xe2\x80\x8e=\xef\xb4\xa1\n"
"  \xe2\x80\x8e&\xd8\xb5\xd9\x8a\xe2\x80\x8e=\xef\xb4\x86\xe2\x80\x8e=\xef\xb4\xa2\n"
"  \xe2\x80\x8e&\xd8\xb6\xe2\x80\x8e=\xef\xba\xbd\xe2\x80\x8e=\xef\xba\xbe\xe2\x80\x8e=\xef\xba\xbf\xe2\x80\x8e=\xef\xbb\x80\n"
"  \xe2\x80\x8e&\xd8\xb6\xd8\xac\xe2\x80\x8e=\xef\xb0\xa2\xe2\x80\x8e=\xef\xb2\xb4\n"
"  \xe2\x80\x8e&\xd8\xb6\xd8\xad\xe2\x80\x8e=\xef\xb0\xa3\xe2\x80\x8e=\xef\xb2\xb5\n"
"  \xe2\x80\x8e&\xd8\xb6\xd8\xad\xd9\x89\xe2\x80\x8e=\xef\xb5\xae\n"
"  \xe2\x80\x8e&\xd8\xb6\xd8\xad\xd9\x8a\xe2\x80\x8e=\xef\xb6\xab\n"
"  \xe2\x80\x8e&\xd8\xb6\xd8\xae\xe2\x80\x8e=\xef\xb0\xa4\xe2\x80\x8e=\xef\xb2\xb6\n"
"  \xe2\x80\x8e&\xd8\xb6\xd8\xae\xd9\x85\xe2\x80\x8e=\xef\xb5\xaf\xe2\x80\x8e=\xef\xb5\xb0\n"
"  \xe2\x80\x8e&\xd8\xb6\xd8\xb1\xe2\x80\x8e=\xef\xb4\x90\xe2\x80\x8e=\xef\xb4\xac\n"
"  \xe2\x80\x8e&\xd8\xb6\xd9\x85\xe2\x80\x8e=\xef\xb0\xa5\xe2\x80\x8e=\xef\xb2\xb7\n"
"  \xe2\x80\x8e&\xd8\xb6\xd9\x89\xe2\x80\x8e=\xef\xb4\x87\xe2\x80\x8e=\xef\xb4\xa3\n"
"  \xe2\x80\x8e&\xd8\xb6\xd9\x8a\xe2\x80\x8e=\xef\xb4\x88\xe2\x80\x8e=\xef\xb4\xa4\n"
"  \xe2\x80\x8e&\xd8\xb7\xe2\x80\x8e=\xef\xbb\x81\xe2\x80\x8e=\xef\xbb\x82\xe2\x80\x8e=\xef\xbb\x83\xe2\x80\x8e=\xef\xbb\x84\n"
"  \xe2\x80\x8e&\xd8\xb7\xd8\xad\xe2\x80\x8e=\xef\xb0\xa6\xe2\x80\x8e=\xef\xb2\xb8\n"
"  \xe2\x80\x8e&\xd8\xb7\xd9\x85\xe2\x80\x8e=\xef\xb0\xa7\xe2\x80\x8e=\xef\xb4\xb3\xe2\x80\x8e=\xef\xb4\xba\n"
"  \xe2\x80\x8e&\xd8\xb7\xd9\x85\xd8\xad\xe2\x80\x8e=\xef\xb5\xb1\xe2\x80\x8e=\xef\xb5\xb2\n"
"  \xe2\x80\x8e&\xd8\xb7\xd9\x85\xd9\x85\xe2\x80\x8e=\xef\xb5\xb3\n"
"  \xe2\x80\x8e&\xd8\xb7\xd9\x85\xd9\x8a\xe2\x80\x8e=\xef\xb5\xb4\n"
"  \xe2\x80\x8e&\xd8\xb7\xd9\x89\xe2\x80\x8e=\xef\xb3\xb5\xe2\x80\x8e=\xef\xb4\x91\n"
"  \xe2\x80\x8e&\xd8\xb7\xd9\x8a\xe2\x80\x8e=\xef\xb3\xb6\xe2\x80\x8e=\xef\xb4\x92\n"
"  \xe2\x80\x8e&\xd8\xb8\xe2\x80\x8e=\xef\xbb\x85\xe2\x80\x8e=\xef\xbb\x86\xe2\x80\x8e=\xef\xbb\x87\xe2\x80\x8e=\xef\xbb\x88\n"
"  \xe2\x80\x8e&\xd8\xb8\xd9\x85\xe2\x80\x8e=\xef\xb0\xa8\xe2\x80\x8e=\xef\xb2\xb9\xe2\x80\x8e=\xef\xb4\xbb\n"
"  \xe2\x80\x8e&\xd8\xb9\xe2\x80\x8e=\xef\xbb\x89\xe2\x80\x8e=\xef\xbb\x8a\xe2\x80\x8e=\xef\xbb\x8b\xe2\x80\x8e=\xef\xbb\x8c\n"
"  \xe2\x80\x8e&\xd8\xb9\xd8\xac\xe2\x80\x8e=\xef\xb0\xa9\xe2\x80\x8e=\xef\xb2\xba\n"
"  \xe2\x80\x8e&\xd8\xb9\xd8\xac\xd9\x85\xe2\x80\x8e=\xef\xb5\xb5\xe2\x80\x8e=\xef\xb7\x84\n"
"  \xe2\x80\x8e&\xd8\xb9\xd9\x84\xd9\x8a\xd9\x87\xe2\x80\x8e<<<\xef\xb7\xb7\n"
"  \xe2\x80\x8e&\xd8\xb9\xd9\x85\xe2\x80\x8e=\xef\xb0\xaa\xe2\x80\x8e=\xef\xb2\xbb\n"
"  \xe2\x80\x8e&\xd8\xb9\xd9\x85\xd9\x85\xe2\x80\x8e=\xef\xb5\xb6\xe2\x80\x8e=\xef\xb5\xb7\n"
"  \xe2\x80\x8e&\xd8\xb9\xd9\x85\xd9\x89\xe2\x80\x8e=\xef\xb5\xb8\n"
"  \xe2\x80\x8e&\xd8\xb9\xd9\x85\xd9\x8a\xe2\x80\x8e=\xef\xb6\xb6\n"
"  \xe2\x80\x8e&\xd8\xb9\xd9\x89\xe2\x80\x8e=\xef\xb3\xb7\xe2\x80\x8e=\xef\xb4\x93\n"
"  \xe2\x80\x8e&\xd8\xb9\xd9\x8a\xe2\x80\x8e=\xef\xb3\xb8\xe2\x80\x8e=\xef\xb4\x94\n"
"  \xe2\x80\x8e&\xd8\xba\xe2\x80\x8e=\xef\xbb\x8d\xe2\x80\x8e=\xef\xbb\x8e\xe2\x80\x8e=\xef\xbb\x8f\xe2\x80\x8e=\xef\xbb\x90\n"
"  \xe2\x80\x8e&\xd8\xba\xd8\xac\xe2\x80\x8e=\xef\xb0\xab\xe2\x80\x8e=\xef\xb2\xbc\n"
"  \xe2\x80\x8e&\xd8\xba\xd9\x85\xe2\x80\x8e=\xef\xb0\xac\xe2\x80\x8e=\xef\xb2\xbd\n"
"  \xe2\x80\x8e&\xd8\xba\xd9\x85\xd9\x85\xe2\x80\x8e=\xef\xb5\xb9\n"
"  \xe2\x80\x8e&\xd8\xba\xd9\x85\xd9\x89\xe2\x80\x8e=\xef\xb5\xbb\n"
"  \xe2\x80\x8e&\xd8\xba\xd9\x85\xd9\x8a\xe2\x80\x8e=\xef\xb5\xba\n"
"  \xe2\x80\x8e&\xd8\xba\xd9\x89\xe2\x80\x8e=\xef\xb3\xb9\xe2\x80\x8e=\xef\xb4\x95\n"
"  \xe2\x80\x8e&\xd8\xba\xd9\x8a\xe2\x80\x8e=\xef\xb3\xba\xe2\x80\x8e=\xef\xb4\x96\n"
"  \xe2\x80\x8e&\xd9\x80\\u064B\xe2\x80\x8e=\xef\xb9\xb1\n"
"  \xe2\x80\x8e&\xd9\x80\\u064E\xe2\x80\x8e=\xef\xb9\xb7\n"
"  \xe2\x80\x8e&\xd9\x80\\u064E\\u0651\xe2\x80\x8e=\xef\xb3\xb2\n"
"  \xe2\x80\x8e&\xd9\x80\\u064F\xe2\x80\x8e=\xef\xb9\xb9\n"
"  \xe2\x80\x8e&\xd9\x80\\u064F\\u0651\xe2\x80\x8e=\xef\xb3\xb3\n"
"  \xe2\x80\x8e&\xd9\x80\\u0650\xe2\x80\x8e=\xef\xb9\xbb\n"
"  \xe2\x80\x8e&\xd9\x80\\u0650\\u0651\xe2\x80\x8e=\xef\xb3\xb4\n"
"  \xe2\x80\x8e&\xd9\x80\\u0651\xe2\x80\x8e=\xef\xb9\xbd\n"
"  \xe2\x80\x8e&\xd9\x80\\u0652\xe2\x80\x8e=\xef\xb9\xbf\n"
"  \xe2\x80\x8e&\xd9\x81\xe2\x80\x8e=\xef\xbb\x91\xe2\x80\x8e=\xef\xbb\x92\xe2\x80\x8e=\xef\xbb\x93\xe2\x80\x8e=\xef\xbb\x94\n"
"  \xe2\x80\x8e&\xd9\x81\xd8\xac\xe2\x80\x8e=\xef\xb0\xad\xe2\x80\x8e=\xef\xb2\xbe\n"
"  \xe2\x80\x8e&\xd9\x81\xd8\xad\xe2\x80\x8e=\xef\xb0\xae\xe2\x80\x8e=\xef\xb2\xbf\n"
"  \xe2\x80\x8e&\xd9\x81\xd8\xae\xe2\x80\x8e=\xef\xb0\xaf\xe2\x80\x8e=\xef\xb3\x80\n"
"  \xe2\x80\x8e&\xd9\x81\xd8\xae\xd9\x85\xe2\x80\x8e=\xef\xb5\xbc\xe2\x80\x8e=\xef\xb5\xbd\n"
"  \xe2\x80\x8e&\xd9\x81\xd9\x85\xe2\x80\x8e=\xef\xb0\xb0\xe2\x80\x8e=\xef\xb3\x81\n"
"  \xe2\x80\x8e&\xd9\x81\xd9\x85\xd9\x8a\xe2\x80\x8e=\xef\xb7\x81\n"
"  \xe2\x80\x8e&\xd9\x81\xd9\x89\xe2\x80\x8e=\xef\xb0\xb1\xe2\x80\x8e=\xef\xb1\xbc\n"
"  \xe2\x80\x8e&\xd9\x81\xd9\x8a\xe2\x80\x8e=\xef\xb0\xb2\xe2\x80\x8e=\xef\xb1\xbd\n"
"  \xe2\x80\x8e&\xd9\x82\xe2\x80\x8e=\xef\xbb\x95\xe2\x80\x8e=\xef\xbb\x96\xe2\x80\x8e=\xef\xbb\x97\xe2\x80\x8e=\xef\xbb\x98\n"
"  \xe2\x80\x8e&\xd9\x82\xd8\xad\xe2\x80\x8e=\xef\xb0\xb3\xe2\x80\x8e=\xef\xb3\x82\n"
"  \xe2\x80\x8e&\xd9\x82\xd9\x84\xdb\x92\xe2\x80\x8e<<<\xef\xb7\xb1\n"
"  \xe2\x80\x8e&\xd9\x82\xd9\x85\xe2\x80\x8e=\xef\xb0\xb4\xe2\x80\x8e=\xef\xb3\x83\n"
"  \xe2\x80\x8e&\xd9\x82\xd9\x85\xd8\xad\xe2\x80\x8e=\xef\xb5\xbe\xe2\x80\x8e=\xef\xb6\xb4\n"
"  \xe2\x80\x8e&\xd9\x82\xd9\x85\xd9\x85\xe2\x80\x8e=\xef\xb5\xbf\n"
"  \xe2\x80\x8e&\xd9\x82\xd9\x85\xd9\x8a\xe2\x80\x8e=\xef\xb6\xb2\n"
"  \xe2\x80\x8e&\xd9\x82\xd9\x89\xe2\x80\x8e=\xef\xb0\xb5\xe2\x80\x8e=\xef\xb1\xbe\n"
"  \xe2\x80\x8e&\xd9\x82\xd9\x8a\xe2\x80\x8e=\xef\xb0\xb6\xe2\x80\x8e=\xef\xb1\xbf\n"
"  \xe2\x80\x8e&\xd9\x83\xe2\x80\x8e=\xef\xbb\x99\xe2\x80\x8e=\xef\xbb\x9a\xe2\x80\x8e=\xef\xbb\x9b\xe2\x80\x8e=\xef\xbb\x9c\n"
"  \xe2\x80\x8e&\xd9\x83\xd8\xa7\xe2\x80\x8e=\xef\xb0\xb7\xe2\x80\x8e=\xef\xb2\x80\n"
"  \xe2\x80\x8e&\xd9\x83\xd8\xac\xe2\x80\x8e=\xef\xb0\xb8\xe2\x80\x8e=\xef\xb3\x84\n"
"  \xe2\x80\x8e&\xd9\x83\xd8\xad\xe2\x80\x8e=\xef\xb0\xb9\xe2\x80\x8e=\xef\xb3\x85\n"
"  \xe2\x80\x8e&\xd9\x83\xd8\xae\xe2\x80\x8e=\xef\xb0\xba\xe2\x80\x8e=\xef\xb3\x86\n"
"  \xe2\x80\x8e&\xd9\x83\xd9\x84\xe2\x80\x8e=\xef\xb0\xbb\xe2\x80\x8e=\xef\xb2\x81\xe2\x80\x8e=\xef\xb3\x87\xe2\x80\x8e=\xef\xb3\xab\n"
"  \xe2\x80\x8e&\xd9\x83\xd9\x85\xe2\x80\x8e=\xef\xb0\xbc\xe2\x80\x8e=\xef\xb2\x82\xe2\x80\x8e=\xef\xb3\x88\xe2\x80\x8e=\xef\xb3\xac\n"
"  \xe2\x80\x8e&\xd9\x83\xd9\x85\xd9\x85\xe2\x80\x8e=\xef\xb6\xbb\xe2\x80\x8e=\xef\xb7\x83\n"
"  \xe2\x80\x8e&\xd9\x83\xd9\x85\xd9\x8a\xe2\x80\x8e=\xef\xb6\xb7\n"
"  \xe2\x80\x8e&\xd9\x83\xd9\x89\xe2\x80\x8e=\xef\xb0\xbd\xe2\x80\x8e=\xef\xb2\x83\n"
"  \xe2\x80\x8e&\xd9\x83\xd9\x8a\xe2\x80\x8e=\xef\xb0\xbe\xe2\x80\x8e=\xef\xb2\x84\n"
"  \xe2\x80\x8e&\xd9\x84\xe2\x80\x8e=\xef\xbb\x9d\xe2\x80\x8e=\xef\xbb\x9e\xe2\x80\x8e=\xef\xbb\x9f\xe2\x80\x8e=\xef\xbb\xa0\n"
"  \xe2\x80\x8e&\xd9\x84\xd8\xa7\xe2\x80\x8e=\xef\xbb\xbb\xe2\x80\x8e=\xef\xbb\xbc\n"
"  \xe2\x80\x8e&\xd9\x84\xd8\xa2\xe2\x80\x8e=\xef\xbb\xb5\xe2\x80\x8e=\xef\xbb\xb6\n"
"  \xe2\x80\x8e&\xd9\x84\xd8\xa3\xe2\x80\x8e=\xef\xbb\xb7\xe2\x80\x8e=\xef\xbb\xb8\n"
"  \xe2\x80\x8e&\xd9\x84\xd8\xa5\xe2\x80\x8e=\xef\xbb\xb9\xe2\x80\x8e=\xef\xbb\xba\n"
"  \xe2\x80\x8e&\xd9\x84\xd8\xac\xe2\x80\x8e=\xef\xb0\xbf\xe2\x80\x8e=\xef\xb3\x89\n"
"  \xe2\x80\x8e&\xd9\x84\xd8\xac\xd8\xac\xe2\x80\x8e=\xef\xb6\x83\xe2\x80\x8e=\xef\xb6\x84\n"
"  \xe2\x80\x8e&\xd9\x84\xd8\xac\xd9\x85\xe2\x80\x8e=\xef\xb6\xba\xe2\x80\x8e=\xef\xb6\xbc\n"
"  \xe2\x80\x8e&\xd9\x84\xd8\xac\xd9\x8a\xe2\x80\x8e=\xef\xb6\xac\n"
"  \xe2\x80\x8e&\xd9\x84\xd8\xad\xe2\x80\x8e=\xef\xb1\x80\xe2\x80\x8e=\xef\xb3\x8a\n"
"  \xe2\x80\x8e&\xd9\x84\xd8\xad\xd9\x85\xe2\x80\x8e=\xef\xb6\x80\xe2\x80\x8e=\xef\xb6\xb5\n"
"  \xe2\x80\x8e&\xd9\x84\xd8\xad\xd9\x89\xe2\x80\x8e=\xef\xb6\x82\n"
"  \xe2\x80\x8e&\xd9\x84\xd8\xad\xd9\x8a\xe2\x80\x8e=\xef\xb6\x81\n"
"  \xe2\x80\x8e&\xd9\x84\xd8\xae\xe2\x80\x8e=\xef\xb1\x81\xe2\x80\x8e=\xef\xb3\x8b\n"
"  \xe2\x80\x8e&\xd9\x84\xd8\xae\xd9\x85\xe2\x80\x8e=\xef\xb6\x85\xe2\x80\x8e=\xef\xb6\x86\n"
"  \xe2\x80\x8e&\xd9\x84\xd9\x85\xe2\x80\x8e=\xef\xb1\x82\xe2\x80\x8e=\xef\xb2\x85\xe2\x80\x8e=\xef\xb3\x8c\xe2\x80\x8e=\xef\xb3\xad\n"
"  \xe2\x80\x8e&\xd9\x84\xd9\x85\xd8\xad\xe2\x80\x8e=\xef\xb6\x87\xe2\x80\x8e=\xef\xb6\x88\n"
"  \xe2\x80\x8e&\xd9\x84\xd9\x85\xd9\x8a\xe2\x80\x8e=\xef\xb6\xad\n"
"  \xe2\x80\x8e&\xd9\x84\xd9\x87\xe2\x80\x8e=\xef\xb3\x8d\n"
"  \xe2\x80\x8e&\xd9\x84\xd9\x89\xe2\x80\x8e=\xef\xb1\x83\xe2\x80\x8e=\xef\xb2\x86\n"
"  \xe2\x80\x8e&\xd9\x84\xd9\x8a\xe2\x80\x8e=\xef\xb1\x84\xe2\x80\x8e=\xef\xb2\x87\n"
"  \xe2\x80\x8e&\xd9\x85\xe2\x80\x8e=\xef\xbb\xa1\xe2\x80\x8e=\xef\xbb\xa2\xe2\x80\x8e=\xef\xbb\xa3\xe2\x80\x8e=\xef\xbb\xa4\n"
"  \xe2\x80\x8e&\xd9\x85\xd8\xa7\xe2\x80\x8e=\xef\xb2\x88\n"
"  \xe2\x80\x8e&\xd9\x85\xd8\xac\xe2\x80\x8e=\xef\xb1\x85\xe2\x80\x8e=\xef\xb3\x8e\n"
"  \xe2\x80\x8e&\xd9\x85\xd8\xac\xd8\xad\xe2\x80\x8e=\xef\xb6\x8c\n"
"  \xe2\x80\x8e&\xd9\x85\xd8\xac\xd8\xae\xe2\x80\x8e=\xef\xb6\x92\n"
"  \xe2\x80\x8e&\xd9\x85\xd8\xac\xd9\x85\xe2\x80\x8e=\xef\xb6\x8d\n"
"  \xe2\x80\x8e&\xd9\x85\xd8\xac\xd9\x8a\xe2\x80\x8e=\xef\xb7\x80\n"
"  \xe2\x80\x8e&\xd9\x85\xd8\xad\xe2\x80\x8e=\xef\xb1\x86\xe2\x80\x8e=\xef\xb3\x8f\n"
"  \xe2\x80\x8e&\xd9\x85\xd8\xad\xd8\xac\xe2\x80\x8e=\xef\xb6\x89\n"
"  \xe2\x80\x8e&\xd9\x85\xd8\xad\xd9\x85\xe2\x80\x8e=\xef\xb6\x8a\n"
"  \xe2\x80\x8e&\xd9\x85\xd8\xad\xd9\x85\xd8\xaf\xe2\x80\x8e<<<\xef\xb7\xb4\n"
"  \xe2\x80\x8e&\xd9\x85\xd8\xad\xd9\x8a\xe2\x80\x8e=\xef\xb6\x8b\n"
"  \xe2\x80\x8e&\xd9\x85\xd8\xae\xe2\x80\x8e=\xef\xb1\x87\xe2\x80\x8e=\xef\xb3\x90\n"
"  \xe2\x80\x8e&\xd9\x85\xd8\xae\xd8\xac\xe2\x80\x8e=\xef\xb6\x8e\n"
"  \xe2\x80\x8e&\xd9\x85\xd8\xae\xd9\x85\xe2\x80\x8e=\xef\xb6\x8f\n"
"  \xe2\x80\x8e&\xd9\x85\xd8\xae\xd9\x8a\xe2\x80\x8e=\xef\xb6\xb9\n"
"  \xe2\x80\x8e&\xd9\x85\xd9\x85\xe2\x80\x8e=\xef\xb1\x88\xe2\x80\x8e=\xef\xb2\x89\xe2\x80\x8e=\xef\xb3\x91\n"
"  \xe2\x80\x8e&\xd9\x85\xd9\x85\xd9\x8a\xe2\x80\x8e=\xef\xb6\xb1\n"
"  \xe2\x80\x8e&\xd9\x85\xd9\x89\xe2\x80\x8e=\xef\xb1\x89\n"
"  \xe2\x80\x8e&\xd9\x85\xd9\x8a\xe2\x80\x8e=\xef\xb1\x8a\n"
"  \xe2\x80\x8e&\xd9\x86\xe2\x80\x8e=\xef\xbb\xa5\xe2\x80\x8e=\xef\xbb\xa6\xe2\x80\x8e=\xef\xbb\xa7\xe2\x80\x8e=\xef\xbb\xa8\n"
"  \xe2\x80\x8e&\xd9\x86\xd8\xac\xe2\x80\x8e=\xef\xb1\x8b\xe2\x80\x8e=\xef\xb3\x92\n"
"  \xe2\x80\x8e&\xd9\x86\xd8\xac\xd8\xad\xe2\x80\x8e=\xef\xb6\xb8\xe2\x80\x8e=\xef\xb6\xbd\n"
"  \xe2\x80\x8e&\xd9\x86\xd8\xac\xd9\x85\xe2\x80\x8e=\xef\xb6\x97\xe2\x80\x8e=\xef\xb6\x98\n"
"  \xe2\x80\x8e&\xd9\x86\xd8\xac\xd9\x89\xe2\x80\x8e=\xef\xb6\x99\n"
"  \xe2\x80\x8e&\xd9\x86\xd8\xac\xd9\x8a\xe2\x80\x8e=\xef\xb7\x87\n"
"  \xe2\x80\x8e&\xd9\x86\xd8\xad\xe2\x80\x8e=\xef\xb1\x8c\xe2\x80\x8e=\xef\xb3\x93\n"
"  \xe2\x80\x8e&\xd9\x86\xd8\xad\xd9\x85\xe2\x80\x8e=\xef\xb6\x95\n"
"  \xe2\x80\x8e&\xd9\x86\xd8\xad\xd9\x89\xe2\x80\x8e=\xef\xb6\x96\n"
"  \xe2\x80\x8e&\xd9\x86\xd8\xad\xd9\x8a\xe2\x80\x8e=\xef\xb6\xb3\n"
"  \xe2\x80\x8e&\xd9\x86\xd8\xae\xe2\x80\x8e=\xef\xb1\x8d\xe2\x80\x8e=\xef\xb3\x94\n"
"  \xe2\x80\x8e&\xd9\x86\xd8\xb1\xe2\x80\x8e=\xef\xb2\x8a\n"
"  \xe2\x80\x8e&\xd9\x86\xd8\xb2\xe2\x80\x8e=\xef\xb2\x8b\n"
"  \xe2\x80\x8e&\xd9\x86\xd9\x85\xe2\x80\x8e=\xef\xb1\x8e\xe2\x80\x8e=\xef\xb2\x8c\xe2\x80\x8e=\xef\xb3\x95\xe2\x80\x8e=\xef\xb3\xae\n"
"  \xe2\x80\x8e&\xd9\x86\xd9\x85\xd9\x89\xe2\x80\x8e=\xef\xb6\x9b\n"
"  \xe2\x80\x8e&\xd9\x86\xd9\x85\xd9\x8a\xe2\x80\x8e=\xef\xb6\x9a\n"
"  \xe2\x80\x8e&\xd9\x86\xd9\x86\xe2\x80\x8e=\xef\xb2\x8d\n"
"  \xe2\x80\x8e&\xd9\x86\xd9\x87\xe2\x80\x8e=\xef\xb3\x96\xe2\x80\x8e=\xef\xb3\xaf\n"
"  \xe2\x80\x8e&\xd9\x86\xd9\x89\xe2\x80\x8e=\xef\xb1\x8f\xe2\x80\x8e=\xef\xb2\x8e\n"
"  \xe2\x80\x8e&\xd9\x86\xd9\x8a\xe2\x80\x8e=\xef\xb1\x90\xe2\x80\x8e=\xef\xb2\x8f\n"
"  \xe2\x80\x8e&\xd9\x87\xe2\x80\x8e=\xef\xbb\xa9\xe2\x80\x8e=\xef\xbb\xaa\xe2\x80\x8e=\xef\xbb\xab\xe2\x80\x8e=\xef\xbb\xac\n"
"  \xe2\x80\x8e&\xd9\x87\xd8\xac\xe2\x80\x8e=\xef\xb1\x91\xe2\x80\x8e=\xef\xb3\x97\n"
"  \xe2\x80\x8e&\xd9\x87\xd9\x85\xe2\x80\x8e=\xef\xb1\x92\xe2\x80\x8e=\xef\xb3\x98\n"
"  \xe2\x80\x8e&\xd9\x87\xd9\x85\xd8\xac\xe2\x80\x8e=\xef\xb6\x93\n"
"  \xe2\x80\x8e&\xd9\x87\xd9\x85\xd9\x85\xe2\x80\x8e=\xef\xb6\x94\n"
"  \xe2\x80\x8e&\xd9\x87\xd9\x89\xe2\x80\x8e=\xef\xb1\x93\n"
"  \xe2\x80\x8e&\xd9\x87\xd9\x8a\xe2\x80\x8e=\xef\xb1\x94\n"
"  \xe2\x80\x8e&\xd9\x87\\u0670\xe2\x80\x8e=\xef\xb3\x99\n"
"  \xe2\x80\x8e&\xd9\x88\xe2\x80\x8e=\xef\xbb\xad\xe2\x80\x8e=\xef\xbb\xae\n"
"  \xe2\x80\x8e&\xd9\x88\xd8\xb3\xd9\x84\xd9\x85\xe2\x80\x8e<<<\xef\xb7\xb8\n"
"  \xe2\x80\x8e&\xd8\xa4\xe2\x80\x8e=\xef\xba\x85\xe2\x80\x8e=\xef\xba\x86\n"
"  \xe2\x80\x8e&\xd9\x89\xe2\x80\x8e=\xef\xaf\xa8\xe2\x80\x8e=\xef\xaf\xa9\xe2\x80\x8e=\xef\xbb\xaf\xe2\x80\x8e=\xef\xbb\xb0\n"
"  \xe2\x80\x8e&\xd9\x89\\u0670\xe2\x80\x8e=\xef\xb1\x9d\xe2\x80\x8e=\xef\xb2\x90\n"
"  \xe2\x80\x8e&\xd9\x8a\xe2\x80\x8e=\xef\xbb\xb1\xe2\x80\x8e=\xef\xbb\xb2\xe2\x80\x8e=\xef\xbb\xb3\xe2\x80\x8e=\xef\xbb\xb4\n"
"  \xe2\x80\x8e&\xd9\x8a\xd8\xac\xe2\x80\x8e=\xef\xb1\x95\xe2\x80\x8e=\xef\xb3\x9a\n"
"  \xe2\x80\x8e&\xd9\x8a\xd8\xac\xd9\x8a\xe2\x80\x8e=\xef\xb6\xaf\n"
"  \xe2\x80\x8e&\xd9\x8a\xd8\xad\xe2\x80\x8e=\xef\xb1\x96\xe2\x80\x8e=\xef\xb3\x9b\n"
"  \xe2\x80\x8e&\xd9\x8a\xd8\xad\xd9\x8a\xe2\x80\x8e=\xef\xb6\xae\n"
"  \xe2\x80\x8e&\xd9\x8a\xd8\xae\xe2\x80\x8e=\xef\xb1\x97\xe2\x80\x8e=\xef\xb3\x9c\n"
"  \xe2\x80\x8e&\xd9\x8a\xd8\xb1\xe2\x80\x8e=\xef\xb2\x91\n"
"  \xe2\x80\x8e&\xd9\x8a\xd8\xb2\xe2\x80\x8e=\xef\xb2\x92\n"
"  \xe2\x80\x8e&\xd9\x8a\xd9\x85\xe2\x80\x8e=\xef\xb1\x98\xe2\x80\x8e=\xef\xb2\x93\xe2\x80\x8e=\xef\xb3\x9d\xe2\x80\x8e=\xef\xb3\xb0\n"
"  \xe2\x80\x8e&\xd9\x8a\xd9\x85\xd9\x85\xe2\x80\x8e=\xef\xb6\x9c\xe2\x80\x8e=\xef\xb6\x9d\n"
"  \xe2\x80\x8e&\xd9\x8a\xd9\x85\xd9\x8a\xe2\x80\x8e=\xef\xb6\xb0\n"
"  \xe2\x80\x8e&\xd9\x8a\xd9\x86\xe2\x80\x8e=\xef\xb2\x94\n"
"  \xe2\x80\x8e&\xd9\x8a\xd9\x87\xe2\x80\x8e=\xef\xb3\x9e\xe2\x80\x8e=\xef\xb3\xb1\n"
"  \xe2\x80\x8e&\xd9\x8a\xd9\x89\xe2\x80\x8e=\xef\xb1\x99\xe2\x80\x8e=\xef\xb2\x95\n"
"  \xe2\x80\x8e&\xd9\x8a\xd9\x8a\xe2\x80\x8e=\xef\xb1\x9a\xe2\x80\x8e=\xef\xb2\x96\n"
"  \xe2\x80\x8e&\xd8\xa6\xe2\x80\x8e=\xef\xba\x89\xe2\x80\x8e=\xef\xba\x8a\xe2\x80\x8e=\xef\xba\x8b\xe2\x80\x8e=\xef\xba\x8c\n"
"  \xe2\x80\x8e&\xd8\xa6\xd8\xa7\xe2\x80\x8e=\xef\xaf\xaa\xe2\x80\x8e=\xef\xaf\xab\n"
"  \xe2\x80\x8e&\xd8\xa6\xd8\xac\xe2\x80\x8e=\xef\xb0\x80\xe2\x80\x8e=\xef\xb2\x97\n"
"  \xe2\x80\x8e&\xd8\xa6\xd8\xad\xe2\x80\x8e=\xef\xb0\x81\xe2\x80\x8e=\xef\xb2\x98\n"
"  \xe2\x80\x8e&\xd8\xa6\xd8\xae\xe2\x80\x8e=\xef\xb2\x99\n"
"  \xe2\x80\x8e&\xd8\xa6\xd8\xb1\xe2\x80\x8e=\xef\xb1\xa4\n"
"  \xe2\x80\x8e&\xd8\xa6\xd8\xb2\xe2\x80\x8e=\xef\xb1\xa5\n"
"  \xe2\x80\x8e&\xd8\xa6\xd9\x85\xe2\x80\x8e=\xef\xb0\x82\xe2\x80\x8e=\xef\xb1\xa6\xe2\x80\x8e=\xef\xb2\x9a\xe2\x80\x8e=\xef\xb3\x9f\n"
"  \xe2\x80\x8e&\xd8\xa6\xd9\x86\xe2\x80\x8e=\xef\xb1\xa7\n"
"  \xe2\x80\x8e&\xd8\xa6\xd9\x87\xe2\x80\x8e=\xef\xb2\x9b\xe2\x80\x8e=\xef\xb3\xa0\n"
"  \xe2\x80\x8e&\xd8\xa6\xd9\x88\xe2\x80\x8e=\xef\xaf\xae\xe2\x80\x8e=\xef\xaf\xaf\n"
"  \xe2\x80\x8e&\xd8\xa6\xd9\x89\xe2\x80\x8e=\xef\xaf\xb9\xe2\x80\x8e=\xef\xaf\xba\xe2\x80\x8e=\xef\xaf\xbb\xe2\x80\x8e=\xef\xb0\x83\xe2\x80\x8e=\xef\xb1\xa8\n"
"  \xe2\x80\x8e&\xd8\xa6\xd9\x8a\xe2\x80\x8e=\xef\xb0\x84\xe2\x80\x8e=\xef\xb1\xa9\n"
"  \xe2\x80\x8e&\xd8\xa6\xdb\x86\xe2\x80\x8e=\xef\xaf\xb2\xe2\x80\x8e=\xef\xaf\xb3\n"
"  \xe2\x80\x8e&\xd8\xa6\xdb\x87\xe2\x80\x8e=\xef\xaf\xb0\xe2\x80\x8e=\xef\xaf\xb1\n"
"  \xe2\x80\x8e&\xd8\xa6\xdb\x88\xe2\x80\x8e=\xef\xaf\xb4\xe2\x80\x8e=\xef\xaf\xb5\n"
"  \xe2\x80\x8e&\xd8\xa6\xdb\x90\xe2\x80\x8e=\xef\xaf\xb6\xe2\x80\x8e=\xef\xaf\xb7\xe2\x80\x8e=\xef\xaf\xb8\n"
"  \xe2\x80\x8e&\xd8\xa6\xdb\x95\xe2\x80\x8e=\xef\xaf\xac\xe2\x80\x8e=\xef\xaf\xad\n"
"  \xe2\x80\x8e&\\u064B\xe2\x80\x8e=\xef\xb9\xb0\n"
"  \xe2\x80\x8e&\\u064C\xe2\x80\x8e=\xef\xb9\xb2\n"
"  \xe2\x80\x8e&\\u064C\\u0651\xe2\x80\x8e=\xef\xb1\x9e\n"
"  \xe2\x80\x8e&\\u064D\xe2\x80\x8e=\xef\xb9\xb4\n"
"  \xe2\x80\x8e&\\u064D\\u0651\xe2\x80\x8e=\xef\xb1\x9f\n"
"  \xe2\x80\x8e&\\u064E\xe2\x80\x8e=\xef\xb9\xb6\n"
"  \xe2\x80\x8e&\\u064E\\u0651\xe2\x80\x8e=\xef\xb1\xa0\n"
"  \xe2\x80\x8e&\\u064F\xe2\x80\x8e=\xef\xb9\xb8\n"
"  \xe2\x80\x8e&\\u064F\\u0651\xe2\x80\x8e=\xef\xb1\xa1\n"
"  \xe2\x80\x8e&\\u0650\xe2\x80\x8e=\xef\xb9\xba\n"
"  \xe2\x80\x8e&\\u0650\\u0651\xe2\x80\x8e=\xef\xb1\xa2\n"
"  \xe2\x80\x8e&\\u0651\xe2\x80\x8e=\xef\xb9\xbc\n"
"  \xe2\x80\x8e&\\u0651\\u0670\xe2\x80\x8e=\xef\xb1\xa3\n"
"  \xe2\x80\x8e&\\u0652\xe2\x80\x8e=\xef\xb9\xbe\n"
"  \xe2\x80\x8e&\xd9\xb1\xe2\x80\x8e=\xef\xad\x90\xe2\x80\x8e=\xef\xad\x91\n"
"  \xe2\x80\x8e&\xd9\xb9\xe2\x80\x8e=\xef\xad\xa6\xe2\x80\x8e=\xef\xad\xa7\xe2\x80\x8e=\xef\xad\xa8\xe2\x80\x8e=\xef\xad\xa9\n"
"  \xe2\x80\x8e&\xd9\xba\xe2\x80\x8e=\xef\xad\x9e\xe2\x80\x8e=\xef\xad\x9f\xe2\x80\x8e=\xef\xad\xa0\xe2\x80\x8e=\xef\xad\xa1\n"
"  \xe2\x80\x8e&\xd9\xbb\xe2\x80\x8e=\xef\xad\x92\xe2\x80\x8e=\xef\xad\x93\xe2\x80\x8e=\xef\xad\x94\xe2\x80\x8e=\xef\xad\x95\n"
"  \xe2\x80\x8e&\xd9\xbe\xe2\x80\x8e=\xef\xad\x96\xe2\x80\x8e=\xef\xad\x97\xe2\x80\x8e=\xef\xad\x98\xe2\x80\x8e=\xef\xad\x99\n"
"  \xe2\x80\x8e&\xd9\xbf\xe2\x80\x8e=\xef\xad\xa2\xe2\x80\x8e=\xef\xad\xa3\xe2\x80\x8e=\xef\xad\xa4\xe2\x80\x8e=\xef\xad\xa5\n"
"  \xe2\x80\x8e&\xda\x80\xe2\x80\x8e=\xef\xad\x9a\xe2\x80\x8e=\xef\xad\x9b\xe2\x80\x8e=\xef\xad\x9c\xe2\x80\x8e=\xef\xad\x9d\n"
"  \xe2\x80\x8e&\xda\x83\xe2\x80\x8e=\xef\xad\xb6\xe2\x80\x8e=\xef\xad\xb7\xe2\x80\x8e=\xef\xad\xb8\xe2\x80\x8e=\xef\xad\xb9\n"
"  \xe2\x80\x8e&\xda\x84\xe2\x80\x8e=\xef\xad\xb2\xe2\x80\x8e=\xef\xad\xb3\xe2\x80\x8e=\xef\xad\xb4\xe2\x80\x8e=\xef\xad\xb5\n"
"  \xe2\x80\x8e&\xda\x86\xe2\x80\x8e=\xef\xad\xba\xe2\x80\x8e=\xef\xad\xbb\xe2\x80\x8e=\xef\xad\xbc\xe2\x80\x8e=\xef\xad\xbd\n"
"  \xe2\x80\x8e&\xda\x87\xe2\x80\x8e=\xef\xad\xbe\xe2\x80\x8e=\xef\xad\xbf\xe2\x80\x8e=\xef\xae\x80\xe2\x80\x8e=\xef\xae\x81\n"
"  \xe2\x80\x8e&\xda\x88\xe2\x80\x8e=\xef\xae\x88\xe2\x80\x8e=\xef\xae\x89\n"
"  \xe2\x80\x8e&\xda\x8c\xe2\x80\x8e=\xef\xae\x84\xe2\x80\x8e=\xef\xae\x85\n"
"  \xe2\x80\x8e&\xda\x8d\xe2\x80\x8e=\xef\xae\x82\xe2\x80\x8e=\xef\xae\x83\n"
"  \xe2\x80\x8e&\xda\x8e\xe2\x80\x8e=\xef\xae\x86\xe2\x80\x8e=\xef\xae\x87\n"
"  \xe2\x80\x8e&\xda\x91\xe2\x80\x8e=\xef\xae\x8c\xe2\x80\x8e=\xef\xae\x8d\n"
"  \xe2\x80\x8e&\xda\x98\xe2\x80\x8e=\xef\xae\x8a\xe2\x80\x8e=\xef\xae\x8b\n"
"  \xe2\x80\x8e&\xda\xa4\xe2\x80\x8e=\xef\xad\xaa\xe2\x80\x8e=\xef\xad\xab\xe2\x80\x8e=\xef\xad\xac\xe2\x80\x8e=\xef\xad\xad\n"
"  \xe2\x80\x8e&\xda\xa6\xe2\x80\x8e=\xef\xad\xae\xe2\x80\x8e=\xef\xad\xaf\xe2\x80\x8e=\xef\xad\xb0\xe2\x80\x8e=\xef\xad\xb1\n"
"  \xe2\x80\x8e&\xda\xa9\xe2\x80\x8e=\xef\xae\x8e\xe2\x80\x8e=\xef\xae\x8f\xe2\x80\x8e=\xef\xae\x90\xe2\x80\x8e=\xef\xae\x91\n"
"  \xe2\x80\x8e&\xda\xad\xe2\x80\x8e=\xef\xaf\x93\xe2\x80\x8e=\xef\xaf\x94\xe2\x80\x8e=\xef\xaf\x95\xe2\x80\x8e=\xef\xaf\x96\n"
"  \xe2\x80\x8e&\xda\xaf\xe2\x80\x8e=\xef\xae\x92\xe2\x80\x8e=\xef\xae\x93\xe2\x80\x8e=\xef\xae\x94\xe2\x80\x8e=\xef\xae\x95\n"
"  \xe2\x80\x8e&\xda\xb1\xe2\x80\x8e=\xef\xae\x9a\xe2\x80\x8e=\xef\xae\x9b\xe2\x80\x8e=\xef\xae\x9c\xe2\x80\x8e=\xef\xae\x9d\n"
"  \xe2\x80\x8e&\xda\xb3\xe2\x80\x8e=\xef\xae\x96\xe2\x80\x8e=\xef\xae\x97\xe2\x80\x8e=\xef\xae\x98\xe2\x80\x8e=\xef\xae\x99\n"
"  \xe2\x80\x8e&\xda\xba\xe2\x80\x8e=\xef\xae\x9e\xe2\x80\x8e=\xef\xae\x9f\n"
"  \xe2\x80\x8e&\xda\xbb\xe2\x80\x8e=\xef\xae\xa0\xe2\x80\x8e=\xef\xae\xa1\xe2\x80\x8e=\xef\xae\xa2\xe2\x80\x8e=\xef\xae\xa3\n"
"  \xe2\x80\x8e&\xda\xbe\xe2\x80\x8e=\xef\xae\xaa\xe2\x80\x8e=\xef\xae\xab\xe2\x80\x8e=\xef\xae\xac\xe2\x80\x8e=\xef\xae\xad\n"
"  \xe2\x80\x8e&\xdb\x81\xe2\x80\x8e=\xef\xae\xa6\xe2\x80\x8e=\xef\xae\xa7\xe2\x80\x8e=\xef\xae\xa8\xe2\x80\x8e=\xef\xae\xa9\n"
"  \xe2\x80\x8e&\xdb\x85\xe2\x80\x8e=\xef\xaf\xa0\xe2\x80\x8e=\xef\xaf\xa1\n"
"  \xe2\x80\x8e&\xdb\x86\xe2\x80\x8e=\xef\xaf\x99\xe2\x80\x8e=\xef\xaf\x9a\n"
"  \xe2\x80\x8e&\xdb\x87\xe2\x80\x8e=\xef\xaf\x97\xe2\x80\x8e=\xef\xaf\x98\n"
"  \xe2\x80\x8e&\xdb\x87\xd9\xb4\xe2\x80\x8e=\xef\xaf\x9d\n"
"  \xe2\x80\x8e&\xdb\x88\xe2\x80\x8e=\xef\xaf\x9b\xe2\x80\x8e=\xef\xaf\x9c\n"
"  \xe2\x80\x8e&\xdb\x89\xe2\x80\x8e=\xef\xaf\xa2\xe2\x80\x8e=\xef\xaf\xa3\n"
"  \xe2\x80\x8e&\xdb\x8b\xe2\x80\x8e=\xef\xaf\x9e\xe2\x80\x8e=\xef\xaf\x9f\n"
"  \xe2\x80\x8e&\xdb\x8c\xe2\x80\x8e=\xef\xaf\xbc\xe2\x80\x8e=\xef\xaf\xbd\xe2\x80\x8e=\xef\xaf\xbe\xe2\x80\x8e=\xef\xaf\xbf\n"
"  \xe2\x80\x8e&\xdb\x90\xe2\x80\x8e=\xef\xaf\xa4\xe2\x80\x8e=\xef\xaf\xa5\xe2\x80\x8e=\xef\xaf\xa6\xe2\x80\x8e=\xef\xaf\xa7\n"
"  \xe2\x80\x8e&\xdb\x92\xe2\x80\x8e=\xef\xae\xae\xe2\x80\x8e=\xef\xae\xaf\n"
"  \xe2\x80\x8e&\xdb\x93\xe2\x80\x8e=\xef\xae\xb0\xe2\x80\x8e=\xef\xae\xb1\n"
"  \xe2\x80\x8e&\xdb\x80\xe2\x80\x8e=\xef\xae\xa4\xe2\x80\x8e=\xef\xae\xa5\n"
"  \n");
}


}}}}

#endif

/*
 * spirit.cpp
 *
 *  Created on: Feb 11, 2015
 *      Author: schoko
 */




#include <vector>
#include <iostream>
#include <cstdint>



#include <boost/spirit/include/karma.hpp>

#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/phoenix_object.hpp>

#include <boost/fusion/include/adapt_adt.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/spirit/home/support/adapt_adt_attributes.hpp>

class subtype {
  public:
    subtype(int chan, int group, int len, std::vector<uint8_t> data) : _channelid(chan), _groupid(group), _len(len), _data(data) {
    }

    int channelid() const { return _channelid; }
    void channelid(int val) { _channelid = val; }

    int groupid() const { return _groupid; }
    void groupid(int val) { _groupid = val; }

    int len() const { return _len; }
    void len(int len) { _len = len; }

    std::vector<uint8_t> data() const { return _data; }
    void data( std::vector<uint8_t>  data) { _data = data; }

  public:
    int _channelid;
    int _groupid;
    int _len;
    std::vector<uint8_t> _data;

};

//BOOST_FUSION_ADAPT_ADT(subtype,
//    (int, int, obj.channelid(), obj.channelid(val))
//    (int, int, obj.groupid(), obj.groupid(val)))

BOOST_FUSION_ADAPT_STRUCT(subtype,
    (int, _channelid)
    (int, _groupid)
    (int, _len)
    (std::vector<uint8_t>, _data))


class mytype {
  public:

    int cmd() const { return _cmd; }
    void cmd(int val) { _cmd = val; }

    int count() const { return _count; }
    void count(int count) { _count = count; }

    std::vector<subtype> vec() const { return _vec; }
    void vec(std::vector<subtype> val) { _vec = val; }

  public:
    int _cmd = 43;
    int _count = 0;
    std::vector<subtype> _vec;// = { subtype(10,50), subtype(20,40), subtype(30,30) };
};

//BOOST_FUSION_ADAPT_ADT(mytype,
//    (int, int, obj.cmd(), obj.cmd(val))
//    //(int, int, obj.vec().size(), )
//    (std::vector<subtype>, std::vector<subtype>, obj.vec(), obj.vec(val)))

BOOST_FUSION_ADAPT_STRUCT(mytype,
    (int, _cmd)
    (int, _count)
    (std::vector<subtype>, _vec))

int main(int argc, char** argv) {

  namespace k = boost::spirit::karma;
  namespace p = boost::phoenix;

  std::vector<uint8_t> datas;
  datas.push_back('a');
  datas.push_back('a');
  datas.push_back('a');
  datas.push_back('a');
  datas.push_back('a');


  subtype s1(1,2, datas.size(), datas);
  subtype s2(3,4, datas.size(), datas);
  subtype s3(5,6, datas.size(), datas);
  subtype s4(7,8, datas.size(), datas);
 
  std::vector<subtype> stypes;
  stypes.push_back(s1);
  stypes.push_back(s2);
  stypes.push_back(s3);
  stypes.push_back(s4);


  mytype t;

  t.vec(stypes);
  t.count(stypes.size());


  std::string str(512, '\0');

  k::rule<decltype(str.begin()), subtype()> sub_generator = ( 
         '(' << k::int_ << '-'// channel
      << k::int_ << '-'// groub
      << k::int_ << '-'// len
      << k::repeat[ k::byte_ ] // data
      << ')'
      );
  

  k::rule<decltype(str.begin()), mytype()> generator =
        k::int_ << '-' //cmd
    <<  k::int_ //count
    << ' '
    << /*int_ <<*/ " :: " << k::repeat[ sub_generator ];

  k::debug(generator);


  bool r = k::generate(str.begin(), generator,  t);

  std::cout << "Generated : " << str << std::endl;

  return 0;
}

/*
 * MyNumbering.hpp
 *
 *  Created on: Mar 8, 2015
 *      Author: schoko
 */

#ifndef SRC_BOOST_COSTUM_ERRORCODES_MYNUMBERING_HPP_
#define SRC_BOOST_COSTUM_ERRORCODES_MYNUMBERING_HPP_

/*
#include <boost/noncopyable.hpp>

#include <ostream>
#include <string>
#include <stdexcept>
#include <functional>



namespace boost
{
  namespace system
  {

    class error_code;
    class error_condition;

    //  "Concept" helpers  ---------------------------------------------------//

    template< class T >
    struct is_error_code_enum { static const bool value = false; };

    template< class T >
    struct is_error_condition_enum { static const bool value = false; };

    //  generic error_conditions  --------------------------------------------//

    namespace errc
    {
      enum errc_t
      {
        success = 0,

      };

    } // namespace errc



    template<> struct is_error_condition_enum<errc::errc_t>
      { static const bool value = true; };


    class error_category : public noncopyable
    {
    public:
      virtual ~error_category(){}

      virtual const char *     name() const  = 0;
      virtual std::string      message( int ev ) const = 0;
      inline virtual error_condition  default_error_condition( int ev ) const  ;
      inline virtual bool             equivalent( int code,
                                           const error_condition & condition ) const  ;
      inline virtual bool             equivalent( const error_code & code,
                                           int condition ) const  ;

      bool operator==(const error_category & rhs) const  { return this == &rhs; }
      bool operator!=(const error_category & rhs) const  { return this != &rhs; }
      bool operator<( const error_category & rhs ) const
      {
        return std::less<const error_category*>()( this, &rhs );
      }
    };

    //  predefined error categories  -----------------------------------------//


     const error_category &  system_category() ;
     const error_category &  generic_category() ;

    //  deprecated synonyms --------------------------------------------------//


    inline const error_category &  get_system_category() { return system_category(); }
    inline const error_category &  get_generic_category() { return generic_category(); }
    inline const error_category &  get_posix_category() { return generic_category(); }
    static const error_category &  posix_category = generic_category();
    static const error_category &  errno_ecat     = generic_category();
    static const error_category &  native_ecat    = system_category();


    //  class error_condition  -----------------------------------------------//

    //  error_conditions are portable, error_codes are system or library specific

    class error_condition
    {
    public:

      // constructors:
      error_condition() noexcept : m_val(0), m_cat(&generic_category()) {}
      error_condition( int val, const error_category & cat ) noexcept : m_val(val), m_cat(&cat) {}

      template <class ErrorConditionEnum>
        error_condition(ErrorConditionEnum e,
          typename boost::enable_if<is_error_condition_enum<ErrorConditionEnum> >::type* = 0) noexcept
      {
        *this = make_error_condition(e);
      }

      // modifiers:

      void assign( int val, const error_category & cat ) noexcept
      {
        m_val = val;
        m_cat = &cat;
      }

      template<typename ErrorConditionEnum>
        typename boost::enable_if<is_error_condition_enum<ErrorConditionEnum>, error_condition>::type &
          operator=( ErrorConditionEnum val ) noexcept
      {
        *this = make_error_condition(val);
        return *this;
      }

      void clear() noexcept
      {
        m_val = 0;
        m_cat = &generic_category();
      }

      // observers:
      int                     value() const noexcept    { return m_val; }
      const error_category &  category() const noexcept { return *m_cat; }
      std::string             message() const  { return m_cat->message(value()); }

      typedef void (*unspecified_bool_type)();
      static void unspecified_bool_true() {}

      operator unspecified_bool_type() const noexcept  // true if error
      {
        return m_val == 0 ? 0 : unspecified_bool_true;
      }

      bool operator!() const noexcept  // true if no error
      {
        return m_val == 0;
      }

      // relationals:
      //  the more symmetrical non-member syntax allows enum
      //  conversions work for both rhs and lhs.
      inline friend bool operator==( const error_condition & lhs,
                                     const error_condition & rhs ) noexcept
      {
        return lhs.m_cat == rhs.m_cat && lhs.m_val == rhs.m_val;
      }

      inline friend bool operator<( const error_condition & lhs,
                                    const error_condition & rhs ) noexcept
        //  the more symmetrical non-member syntax allows enum
        //  conversions work for both rhs and lhs.
      {
        return lhs.m_cat < rhs.m_cat
          || (lhs.m_cat == rhs.m_cat && lhs.m_val < rhs.m_val);
      }

    private:
      int                     m_val;
      const error_category *  m_cat;

    };

    //  class error_code  ----------------------------------------------------//

    //  We want error_code to be a value type that can be copied without slicing
    //  and without requiring heap allocation, but we also want it to have
    //  polymorphic behavior based on the error category. This is achieved by
    //  abstract base class error_category supplying the polymorphic behavior,
    //  and error_code containing a pointer to an object of a type derived
    //  from error_category.
    class error_code
    {
    public:

      // constructors:
      error_code() noexcept : m_val(0), m_cat(&system_category()) {}
      error_code( int val, const error_category & cat ) noexcept : m_val(val), m_cat(&cat) {}

      template <class ErrorCodeEnum>
        error_code(ErrorCodeEnum e,
          typename boost::enable_if<is_error_code_enum<ErrorCodeEnum> >::type* = 0) noexcept
      {
        *this = make_error_code(e);
      }

      // modifiers:
      void assign( int val, const error_category & cat ) noexcept
      {
        m_val = val;
        m_cat = &cat;
      }

      template<typename ErrorCodeEnum>
        typename boost::enable_if<is_error_code_enum<ErrorCodeEnum>, error_code>::type &
          operator=( ErrorCodeEnum val ) noexcept
      {
        *this = make_error_code(val);
        return *this;
      }

      void clear() noexcept
      {
        m_val = 0;
        m_cat = &system_category();
      }

      // observers:
      int                     value() const  noexcept   { return m_val; }
      const error_category &  category() const noexcept { return *m_cat; }
      error_condition         default_error_condition() const noexcept  { return m_cat->default_error_condition(value()); }
      std::string             message() const  { return m_cat->message(value()); }

      typedef void (*unspecified_bool_type)();
      static void unspecified_bool_true() {}

      operator unspecified_bool_type() const  noexcept // true if error
      {
        return m_val == 0 ? 0 : unspecified_bool_true;
      }

      bool operator!() const  noexcept // true if no error
      {
        return m_val == 0;
      }

      // relationals:
      inline friend bool operator==( const error_code & lhs,
                                     const error_code & rhs ) noexcept
        //  the more symmetrical non-member syntax allows enum
        //  conversions work for both rhs and lhs.
      {
        return lhs.m_cat == rhs.m_cat && lhs.m_val == rhs.m_val;
      }

      inline friend bool operator<( const error_code & lhs,
                                    const error_code & rhs ) noexcept
        //  the more symmetrical non-member syntax allows enum
        //  conversions work for both rhs and lhs.
      {
        return lhs.m_cat < rhs.m_cat
          || (lhs.m_cat == rhs.m_cat && lhs.m_val < rhs.m_val);
      }

    private:
      int                     m_val;
      const error_category *  m_cat;

    };

    //  predefined error_code object used as "throw on error" tag

     extern error_code throws;


    //  Moving from a "throws" object to a "throws" function without breaking
    //  existing code is a bit of a problem. The workaround is to place the
    //  "throws" function in namespace boost rather than namespace boost::system.

  }  // namespace system

  namespace detail { inline system::error_code * throws() { return 0; } }
    //  Misuse of the error_code object is turned into a noisy failure by
    //  poisoning the reference. This particular implementation doesn't
    //  produce warnings or errors from popular compilers, is very efficient
    //  (as determined by inspecting generated code), and does not suffer
    //  from order of initialization problems. In practice, it also seems
    //  cause user function error handling implementation errors to be detected
    //  very early in the development cycle.

  inline system::error_code & throws()
    { return *detail::throws(); }

  namespace system
  {
    //  non-member functions  ------------------------------------------------//

    inline bool operator!=( const error_code & lhs,
                            const error_code & rhs ) noexcept
    {
      return !(lhs == rhs);
    }

    inline bool operator!=( const error_condition & lhs,
                            const error_condition & rhs ) noexcept
    {
      return !(lhs == rhs);
    }

    inline bool operator==( const error_code & code,
                            const error_condition & condition ) noexcept
    {
      return code.category().equivalent( code.value(), condition )
        || condition.category().equivalent( code, condition.value() );
    }

    inline bool operator!=( const error_code & lhs,
                            const error_condition & rhs ) noexcept
    {
      return !(lhs == rhs);
    }

    inline bool operator==( const error_condition & condition,
                            const error_code & code ) noexcept
    {
      return condition.category().equivalent( code, condition.value() )
        || code.category().equivalent( code.value(), condition );
    }

    inline bool operator!=( const error_condition & lhs,
                            const error_code & rhs ) noexcept
    {
      return !(lhs == rhs);
    }

    // TODO: both of these may move elsewhere, but the LWG hasn't spoken yet.

    template <class charT, class traits>
    inline std::basic_ostream<charT,traits>&
      operator<< (std::basic_ostream<charT,traits>& os, error_code ec)
    {
      os << ec.category().name() << ':' << ec.value();
      return os;
    }

    inline std::size_t hash_value( const error_code & ec )
    {
      return static_cast<std::size_t>(ec.value())
        + reinterpret_cast<std::size_t>(&ec.category());
    }

    //  make_* functions for errc::errc_t  -----------------------------//

    namespace errc
    {
      //  explicit conversion:
      inline error_code make_error_code( errc_t e ) noexcept
        { return error_code( e, generic_category() ); }

      //  implicit conversion:
      inline error_condition make_error_condition( errc_t e ) noexcept
        { return error_condition( e, generic_category() ); }
    }

    //  error_category default implementation  -------------------------------//

    error_condition error_category::default_error_condition( int ev ) const noexcept
    {
      return error_condition( ev, *this );
    }

    bool error_category::equivalent( int code,
      const error_condition & condition ) const noexcept
    {
      return default_error_condition( code ) == condition;
    }

    bool error_category::equivalent( const error_code & code,
      int condition ) const noexcept
    {
      return *this == code.category() && code.value() == condition;
    }

  } // namespace system
} // namespace boost



*/
#endif /* SRC_BOOST_COSTUM_ERRORCODES_MYNUMBERING_HPP_ */


/*
 [auto_generated]
 boost/numeric/odeint/iterator/adaptive_time_iterator.hpp

 [begin_description]
 Iterator for iterating throught the solution of an ODE with adaptive step size. The dereferenced types containes also the time.
 [end_description]

 Copyright 2009-2011 Karsten Ahnert
 Copyright 2009-2011 Mario Mulansky

 Distributed under the Boost Software License, Version 1.0.
 (See accompanying file LICENSE_1_0.txt or
 copy at http://www.boost.org/LICENSE_1_0.txt)
 */


#ifndef BOOST_NUMERIC_ODEINT_ITERATOR_ADAPTIVE_TIME_ITERATOR_HPP_INCLUDED
#define BOOST_NUMERIC_ODEINT_ITERATOR_ADAPTIVE_TIME_ITERATOR_HPP_INCLUDED



#include <boost/numeric/odeint/stepper/stepper_categories.hpp>
#include <boost/numeric/odeint/util/stepper_traits.hpp>
#include <boost/numeric/odeint/iterator/impl/adaptive_iterator_impl.hpp>

namespace boost {
namespace numeric {
namespace odeint {


    template< class Stepper , class System , class State ,
              class StepperTag = typename base_tag< typename traits::stepper_category< Stepper >::type >::type >
    class adaptive_time_iterator : public adaptive_iterator_impl<
            adaptive_time_iterator< Stepper , System , State , StepperTag > ,
            Stepper , System , State , detail::ode_state_time_iterator_tag , StepperTag
        >
    {
        typedef typename traits::time_type< Stepper >::type time_type;
        typedef adaptive_time_iterator< Stepper , System , State , StepperTag > iterator_type;

    public:
        adaptive_time_iterator( Stepper stepper , System sys , State &s , time_type t , time_type t_end , time_type dt )
            : adaptive_iterator_impl< iterator_type , Stepper , System , State , detail::ode_state_time_iterator_tag , StepperTag >( stepper , sys , s , t , t_end , dt )
        {}

        adaptive_time_iterator( Stepper stepper , System sys , State &s )
            : adaptive_iterator_impl< iterator_type , Stepper , System , State , detail::ode_state_time_iterator_tag , StepperTag >( stepper , sys , s )
        {}
    };




    template< class Stepper , class System , class State >
    adaptive_time_iterator< Stepper , System , State > make_adaptive_time_iterator_begin(
        Stepper stepper ,
        System system , 
        State &x ,
        typename traits::time_type< Stepper >::type t ,
        typename traits::time_type< Stepper >::type t_end ,
        typename traits::time_type< Stepper >::type dt )
    {
        return adaptive_time_iterator< Stepper , System , State >( stepper , system , x , t , t_end , dt );
    }

    template< class Stepper , class System , class State >
    adaptive_time_iterator< Stepper , System , State > make_adaptive_time_iterator_end(
        Stepper stepper ,
        System system , 
        State &x )
    {
        return adaptive_time_iterator< Stepper , System , State >( stepper , system , x );
    }


    template< class Stepper , class System , class State >
    std::pair< adaptive_time_iterator< Stepper , System , State > , adaptive_time_iterator< Stepper , System , State > >
    make_adaptive_time_range(
        Stepper stepper ,
        System system , 
        State &x ,
        typename traits::time_type< Stepper >::type t_start ,
        typename traits::time_type< Stepper >::type t_end ,
        typename traits::time_type< Stepper >::type dt )
    {
        return std::make_pair(
            adaptive_time_iterator< Stepper , System , State >( stepper , system , x , t_start , t_end , dt ) ,
            adaptive_time_iterator< Stepper , System , State >( stepper , system , x ) );
    }






    /**
     * \fn make_adaptive_time_iterator_begin( Stepper stepper , System system , typename Stepper::state_type &x , typename Stepper::time_type t , typename Stepper::time_type t_end , typename Stepper::time_type dt )
     *
     * \brief Factory function for adaptive_time_iterator. Constructs a begin iterator.
     *
     * \param stepper The stepper to use during the iteration.
     * \param system The system function (ODE) to solve.
     * \param x The initial state. adaptive_time_iterator stores a reference of s and changes its value during the iteration.
     * \param t The initial time.
     * \param t_end The end time, at which the iteration should stop.
     * \param dt The initial time step.
     * \returns The adaptive time iterator.
     */


    /**
     * \fn make_adaptive_iterator_end( Stepper stepper , System system , typename Stepper::state_type &x )
     * \brief Factory function for adaptive_time_iterator. Constructs a end iterator.
     *
     * \param stepper The stepper to use during the iteration.
     * \param system The system function (ODE) to solve.
     * \param x The initial state. adaptive_time_iterator stores a reference of s and changes its value during the iteration.
     * \returns The adaptive time iterator.
     */


    /**
     * \fn make_adaptive_range( Stepper stepper , System system , typename Stepper::state_type &x , typename Stepper::time_type t_start , typename Stepper::time_type t_end , typename Stepper::time_type dt )
     *
     * \brief Factory function to construct a single pass range of adaptive time iterators. A range is here a pair of adaptive_time_iterators.
     *
     * \param stepper The stepper to use during the iteration.
     * \param system The system function (ODE) to solve.
     * \param x The initial state. adaptive_time_iterator stores a reference of s and changes its value during the iteration.
     * \param t The initial time.
     * \param t_end The end time, at which the iteration should stop.
     * \param dt The initial time step.
     * \returns The adaptive time range.
     */


} // namespace odeint
} // namespace numeric
} // namespace boost


#endif // BOOST_NUMERIC_ODEINT_ITERATOR_ADAPTIVE_TIME_ITERATOR_HPP_INCLUDED

/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** __VA_OPT__ compatibility layer
*/

#ifndef LIBMY_PRIV_VAOPT_H
#define LIBMY_PRIV_VAOPT_H

#define PP_THIRD_ARG(a,b,c,...) c
#define VA_OPT_SUPPORTED_I(...) PP_THIRD_ARG(__VA_OPT__(,),true,false,)
#define VA_OPT_SUPPORTED VA_OPT_SUPPORTED_I(?)

#if VA_OPT_SUPPORTED
    #define MY__VA_OPT(T, ...) __VA_OPT__(T)
    #define MY__VA_OPT_COMMA(...) __VA_OPT__(,)
#else
    #define MY__VA_OPT(T, ...) T
    #define MY__VA_OPT_COMMA(...) ,
#endif

#undef PP_THIRD_ARG
#undef VA_OPT_SUPPORTED_I
#undef VA_OPT_SUPPORTED

#endif /* LIBMY_PRIV_VAOPT_H */

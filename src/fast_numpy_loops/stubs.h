#pragma once

// Ugly macro exapnsion to handle which ufunc
// TODO: the ufunc callback needs to use enums
#define DEF_BINARY_USTUB(_FUNC_, _ATYPE_) void F##_ATYPE_##_FUNC_(char **args, const npy_intp *dimensions, const npy_intp *steps, void*innerloop) { \
    return AtopBinaryMathFunction(args, dimensions, steps, innerloop, _FUNC_, _ATYPE_);}

#define DEF_BINARY_USTUB_EXPAND(_FUNC_) \
    DEF_BINARY_USTUB(_FUNC_, ATOP_BOOL); \
    DEF_BINARY_USTUB(_FUNC_, ATOP_INT8); \
    DEF_BINARY_USTUB(_FUNC_, ATOP_UINT8); \
    DEF_BINARY_USTUB(_FUNC_, ATOP_INT16); \
    DEF_BINARY_USTUB(_FUNC_, ATOP_UINT16); \
    DEF_BINARY_USTUB(_FUNC_, ATOP_INT32); \
    DEF_BINARY_USTUB(_FUNC_, ATOP_UINT32); \
    DEF_BINARY_USTUB(_FUNC_, ATOP_INT64); \
    DEF_BINARY_USTUB(_FUNC_, ATOP_UINT64); \
    DEF_BINARY_USTUB(_FUNC_, ATOP_INT128); \
    DEF_BINARY_USTUB(_FUNC_, ATOP_UINT128); \
    DEF_BINARY_USTUB(_FUNC_, ATOP_FLOAT); \
    DEF_BINARY_USTUB(_FUNC_, ATOP_DOUBLE); \
    DEF_BINARY_USTUB(_FUNC_, ATOP_LONGDOUBLE);

// For however many functions there are
DEF_BINARY_USTUB_EXPAND(0)
DEF_BINARY_USTUB_EXPAND(1)
DEF_BINARY_USTUB_EXPAND(2)
DEF_BINARY_USTUB_EXPAND(3)
DEF_BINARY_USTUB_EXPAND(4)
DEF_BINARY_USTUB_EXPAND(5)
DEF_BINARY_USTUB_EXPAND(6)
DEF_BINARY_USTUB_EXPAND(7)
DEF_BINARY_USTUB_EXPAND(8)
DEF_BINARY_USTUB_EXPAND(9)
DEF_BINARY_USTUB_EXPAND(10)
DEF_BINARY_USTUB_EXPAND(11)
DEF_BINARY_USTUB_EXPAND(12)
DEF_BINARY_USTUB_EXPAND(13)
DEF_BINARY_USTUB_EXPAND(14)
DEF_BINARY_USTUB_EXPAND(15)
DEF_BINARY_USTUB_EXPAND(16)
DEF_BINARY_USTUB_EXPAND(17)
DEF_BINARY_USTUB_EXPAND(18)
DEF_BINARY_USTUB_EXPAND(19)
DEF_BINARY_USTUB_EXPAND(20)
DEF_BINARY_USTUB_EXPAND(21)
DEF_BINARY_USTUB_EXPAND(22)
DEF_BINARY_USTUB_EXPAND(23)
DEF_BINARY_USTUB_EXPAND(24)
DEF_BINARY_USTUB_EXPAND(25)
DEF_BINARY_USTUB_EXPAND(26)

#define DEF_BINARY_USTUB_NAME(_FUNC_) \
    FATOP_BOOL##_FUNC_, \
    FATOP_INT8##_FUNC_, \
    FATOP_UINT8##_FUNC_, \
    FATOP_INT16##_FUNC_, \
    FATOP_UINT16##_FUNC_, \
    FATOP_INT32##_FUNC_, \
    FATOP_UINT32##_FUNC_, \
    FATOP_INT64##_FUNC_, \
    FATOP_UINT64##_FUNC_, \
    FATOP_INT128##_FUNC_, \
    FATOP_UINT128##_FUNC_, \
    FATOP_FLOAT##_FUNC_, \
    FATOP_DOUBLE##_FUNC_, \
    FATOP_LONGDOUBLE##_FUNC_ 

PyUFuncGenericFunction g_UFuncGenericLUT[BINARY_OPERATION::BINARY_LAST][ATOP_LAST] =
{
{DEF_BINARY_USTUB_NAME(0)},
{DEF_BINARY_USTUB_NAME(1)},
{DEF_BINARY_USTUB_NAME(2)},
{DEF_BINARY_USTUB_NAME(3)},
{DEF_BINARY_USTUB_NAME(4)},
{DEF_BINARY_USTUB_NAME(5)},
{DEF_BINARY_USTUB_NAME(6)},
{DEF_BINARY_USTUB_NAME(7)},
{DEF_BINARY_USTUB_NAME(8)},
{DEF_BINARY_USTUB_NAME(9)},
{DEF_BINARY_USTUB_NAME(10)},
{DEF_BINARY_USTUB_NAME(11)},
{DEF_BINARY_USTUB_NAME(12)},
{DEF_BINARY_USTUB_NAME(13)},
{DEF_BINARY_USTUB_NAME(14)},
{DEF_BINARY_USTUB_NAME(15)},
{DEF_BINARY_USTUB_NAME(16)},
{DEF_BINARY_USTUB_NAME(17)},
{DEF_BINARY_USTUB_NAME(18)},
{DEF_BINARY_USTUB_NAME(19)},
{DEF_BINARY_USTUB_NAME(20)},
{DEF_BINARY_USTUB_NAME(21)},
{DEF_BINARY_USTUB_NAME(22)},
{DEF_BINARY_USTUB_NAME(23)},
{DEF_BINARY_USTUB_NAME(24)},
{DEF_BINARY_USTUB_NAME(25)},
{DEF_BINARY_USTUB_NAME(26)},
};


#define DEF_COMP_USTUB(_FUNC_, _ATYPE_) void COMPF##_ATYPE_##_FUNC_(char **args, const npy_intp *dimensions, const npy_intp *steps, void*innerloop) { \
    return AtopCompareMathFunction(args, dimensions, steps, innerloop, _FUNC_, _ATYPE_);}

#define DEF_COMP_USTUB_EXPAND(_FUNC_) \
    DEF_COMP_USTUB(_FUNC_, ATOP_BOOL); \
    DEF_COMP_USTUB(_FUNC_, ATOP_INT8); \
    DEF_COMP_USTUB(_FUNC_, ATOP_UINT8); \
    DEF_COMP_USTUB(_FUNC_, ATOP_INT16); \
    DEF_COMP_USTUB(_FUNC_, ATOP_UINT16); \
    DEF_COMP_USTUB(_FUNC_, ATOP_INT32); \
    DEF_COMP_USTUB(_FUNC_, ATOP_UINT32); \
    DEF_COMP_USTUB(_FUNC_, ATOP_INT64); \
    DEF_COMP_USTUB(_FUNC_, ATOP_UINT64); \
    DEF_COMP_USTUB(_FUNC_, ATOP_INT128); \
    DEF_COMP_USTUB(_FUNC_, ATOP_UINT128); \
    DEF_COMP_USTUB(_FUNC_, ATOP_FLOAT); \
    DEF_COMP_USTUB(_FUNC_, ATOP_DOUBLE); \
    DEF_COMP_USTUB(_FUNC_, ATOP_LONGDOUBLE);

// For however many functions there are
DEF_COMP_USTUB_EXPAND(0)
DEF_COMP_USTUB_EXPAND(1)
DEF_COMP_USTUB_EXPAND(2)
DEF_COMP_USTUB_EXPAND(3)
DEF_COMP_USTUB_EXPAND(4)
DEF_COMP_USTUB_EXPAND(5)

#define DEF_COMP_USTUB_NAME(_FUNC_) \
    COMPFATOP_BOOL##_FUNC_, \
    COMPFATOP_INT8##_FUNC_, \
    COMPFATOP_UINT8##_FUNC_, \
    COMPFATOP_INT16##_FUNC_, \
    COMPFATOP_UINT16##_FUNC_, \
    COMPFATOP_INT32##_FUNC_, \
    COMPFATOP_UINT32##_FUNC_, \
    COMPFATOP_INT64##_FUNC_, \
    COMPFATOP_UINT64##_FUNC_, \
    COMPFATOP_INT128##_FUNC_, \
    COMPFATOP_UINT128##_FUNC_, \
    COMPFATOP_FLOAT##_FUNC_, \
    COMPFATOP_DOUBLE##_FUNC_, \
    COMPFATOP_LONGDOUBLE##_FUNC_ 

PyUFuncGenericFunction g_UFuncCompareLUT[COMP_OPERATION::CMP_LAST][ATOP_LAST] =
{
{DEF_COMP_USTUB_NAME(0)},
{DEF_COMP_USTUB_NAME(1)},
{DEF_COMP_USTUB_NAME(2)},
{DEF_COMP_USTUB_NAME(3)},
{DEF_COMP_USTUB_NAME(4)},
{DEF_COMP_USTUB_NAME(5)} };



#define DEF_UNARY_USTUB(_FUNC_, _ATYPE_) void UNARYF##_ATYPE_##_FUNC_(char **args, const npy_intp *dimensions, const npy_intp *steps, void*innerloop) { \
    return AtopUnaryMathFunction(args, dimensions, steps, innerloop, _FUNC_, _ATYPE_);}

#define DEF_UNARY_USTUB_EXPAND(_FUNC_) \
    DEF_UNARY_USTUB(_FUNC_, ATOP_BOOL); \
    DEF_UNARY_USTUB(_FUNC_, ATOP_INT8); \
    DEF_UNARY_USTUB(_FUNC_, ATOP_UINT8); \
    DEF_UNARY_USTUB(_FUNC_, ATOP_INT16); \
    DEF_UNARY_USTUB(_FUNC_, ATOP_UINT16); \
    DEF_UNARY_USTUB(_FUNC_, ATOP_INT32); \
    DEF_UNARY_USTUB(_FUNC_, ATOP_UINT32); \
    DEF_UNARY_USTUB(_FUNC_, ATOP_INT64); \
    DEF_UNARY_USTUB(_FUNC_, ATOP_UINT64); \
    DEF_UNARY_USTUB(_FUNC_, ATOP_INT128); \
    DEF_UNARY_USTUB(_FUNC_, ATOP_UINT128); \
    DEF_UNARY_USTUB(_FUNC_, ATOP_FLOAT); \
    DEF_UNARY_USTUB(_FUNC_, ATOP_DOUBLE); \
    DEF_UNARY_USTUB(_FUNC_, ATOP_LONGDOUBLE);

// For however many functions there are
DEF_UNARY_USTUB_EXPAND(0)
DEF_UNARY_USTUB_EXPAND(1)
DEF_UNARY_USTUB_EXPAND(2)
DEF_UNARY_USTUB_EXPAND(3)
DEF_UNARY_USTUB_EXPAND(4)
DEF_UNARY_USTUB_EXPAND(5)
DEF_UNARY_USTUB_EXPAND(6)
DEF_UNARY_USTUB_EXPAND(7)
DEF_UNARY_USTUB_EXPAND(8)
DEF_UNARY_USTUB_EXPAND(9)
DEF_UNARY_USTUB_EXPAND(10)
DEF_UNARY_USTUB_EXPAND(11)
DEF_UNARY_USTUB_EXPAND(12)
DEF_UNARY_USTUB_EXPAND(13)
DEF_UNARY_USTUB_EXPAND(14)
DEF_UNARY_USTUB_EXPAND(15)
DEF_UNARY_USTUB_EXPAND(16)
DEF_UNARY_USTUB_EXPAND(17)
DEF_UNARY_USTUB_EXPAND(18)
DEF_UNARY_USTUB_EXPAND(19)
DEF_UNARY_USTUB_EXPAND(20)
DEF_UNARY_USTUB_EXPAND(21)
DEF_UNARY_USTUB_EXPAND(22)
DEF_UNARY_USTUB_EXPAND(23)
DEF_UNARY_USTUB_EXPAND(24)
DEF_UNARY_USTUB_EXPAND(25)
DEF_UNARY_USTUB_EXPAND(26)
DEF_UNARY_USTUB_EXPAND(27)
DEF_UNARY_USTUB_EXPAND(28)
DEF_UNARY_USTUB_EXPAND(29)

#define DEF_UNARY_USTUB_NAME(_FUNC_) \
    UNARYFATOP_BOOL##_FUNC_, \
    UNARYFATOP_INT8##_FUNC_, \
    UNARYFATOP_UINT8##_FUNC_, \
    UNARYFATOP_INT16##_FUNC_, \
    UNARYFATOP_UINT16##_FUNC_, \
    UNARYFATOP_INT32##_FUNC_, \
    UNARYFATOP_UINT32##_FUNC_, \
    UNARYFATOP_INT64##_FUNC_, \
    UNARYFATOP_UINT64##_FUNC_, \
    UNARYFATOP_INT128##_FUNC_, \
    UNARYFATOP_UINT128##_FUNC_, \
    UNARYFATOP_FLOAT##_FUNC_, \
    UNARYFATOP_DOUBLE##_FUNC_, \
    UNARYFATOP_LONGDOUBLE##_FUNC_ 

PyUFuncGenericFunction g_UFuncUnaryLUT[UNARY_OPERATION::UNARY_LAST][ATOP_LAST] =
{
{DEF_UNARY_USTUB_NAME(0)},
{DEF_UNARY_USTUB_NAME(1)},
{DEF_UNARY_USTUB_NAME(2)},
{DEF_UNARY_USTUB_NAME(3)},
{DEF_UNARY_USTUB_NAME(4)},
{DEF_UNARY_USTUB_NAME(5)},
{DEF_UNARY_USTUB_NAME(6)},
{DEF_UNARY_USTUB_NAME(7)},
{DEF_UNARY_USTUB_NAME(8)},
{DEF_UNARY_USTUB_NAME(9)},
{DEF_UNARY_USTUB_NAME(10)},
{DEF_UNARY_USTUB_NAME(11)},
{DEF_UNARY_USTUB_NAME(12)},
{DEF_UNARY_USTUB_NAME(13)},
{DEF_UNARY_USTUB_NAME(14)},
{DEF_UNARY_USTUB_NAME(15)},
{DEF_UNARY_USTUB_NAME(16)},
{DEF_UNARY_USTUB_NAME(17)},
{DEF_UNARY_USTUB_NAME(18)},
{DEF_UNARY_USTUB_NAME(19)},
{DEF_UNARY_USTUB_NAME(20)},
{DEF_UNARY_USTUB_NAME(21)},
{DEF_UNARY_USTUB_NAME(22)},
{DEF_UNARY_USTUB_NAME(23)},
{DEF_UNARY_USTUB_NAME(24)},
{DEF_UNARY_USTUB_NAME(25)},
{DEF_UNARY_USTUB_NAME(26)},
{DEF_UNARY_USTUB_NAME(27)},
{DEF_UNARY_USTUB_NAME(28)},
{DEF_UNARY_USTUB_NAME(29)},
};



//=============================================================================
// Trig

#define DEF_TRIG_USTUB(_FUNC_, _ATYPE_) void TRIGF##_ATYPE_##_FUNC_(char **args, const npy_intp *dimensions, const npy_intp *steps, void*innerloop) { \
    return AtopTrigMathFunction(args, dimensions, steps, innerloop, _FUNC_, _ATYPE_);}

#define DEF_TRIG_USTUB_EXPAND(_FUNC_) \
    DEF_TRIG_USTUB(_FUNC_, ATOP_BOOL); \
    DEF_TRIG_USTUB(_FUNC_, ATOP_INT8); \
    DEF_TRIG_USTUB(_FUNC_, ATOP_UINT8); \
    DEF_TRIG_USTUB(_FUNC_, ATOP_INT16); \
    DEF_TRIG_USTUB(_FUNC_, ATOP_UINT16); \
    DEF_TRIG_USTUB(_FUNC_, ATOP_INT32); \
    DEF_TRIG_USTUB(_FUNC_, ATOP_UINT32); \
    DEF_TRIG_USTUB(_FUNC_, ATOP_INT64); \
    DEF_TRIG_USTUB(_FUNC_, ATOP_UINT64); \
    DEF_TRIG_USTUB(_FUNC_, ATOP_INT128); \
    DEF_TRIG_USTUB(_FUNC_, ATOP_UINT128); \
    DEF_TRIG_USTUB(_FUNC_, ATOP_FLOAT); \
    DEF_TRIG_USTUB(_FUNC_, ATOP_DOUBLE); \
    DEF_TRIG_USTUB(_FUNC_, ATOP_LONGDOUBLE);

// For however many functions there are
DEF_TRIG_USTUB_EXPAND(0)
DEF_TRIG_USTUB_EXPAND(1)
DEF_TRIG_USTUB_EXPAND(2)
DEF_TRIG_USTUB_EXPAND(3)
DEF_TRIG_USTUB_EXPAND(4)
DEF_TRIG_USTUB_EXPAND(5)
DEF_TRIG_USTUB_EXPAND(6)
DEF_TRIG_USTUB_EXPAND(7)
DEF_TRIG_USTUB_EXPAND(8)
DEF_TRIG_USTUB_EXPAND(9)
DEF_TRIG_USTUB_EXPAND(10)
DEF_TRIG_USTUB_EXPAND(11)
DEF_TRIG_USTUB_EXPAND(12)
DEF_TRIG_USTUB_EXPAND(13)
DEF_TRIG_USTUB_EXPAND(14)
DEF_TRIG_USTUB_EXPAND(15)
DEF_TRIG_USTUB_EXPAND(16)
DEF_TRIG_USTUB_EXPAND(17)
DEF_TRIG_USTUB_EXPAND(18)
DEF_TRIG_USTUB_EXPAND(19)
DEF_TRIG_USTUB_EXPAND(20)
DEF_TRIG_USTUB_EXPAND(21)
DEF_TRIG_USTUB_EXPAND(22)
DEF_TRIG_USTUB_EXPAND(23)
DEF_TRIG_USTUB_EXPAND(24)
DEF_TRIG_USTUB_EXPAND(25)
DEF_TRIG_USTUB_EXPAND(26)
DEF_TRIG_USTUB_EXPAND(27)
DEF_TRIG_USTUB_EXPAND(28)
DEF_TRIG_USTUB_EXPAND(29)

#define DEF_TRIG_USTUB_NAME(_FUNC_) \
    TRIGFATOP_BOOL##_FUNC_, \
    TRIGFATOP_INT8##_FUNC_, \
    TRIGFATOP_UINT8##_FUNC_, \
    TRIGFATOP_INT16##_FUNC_, \
    TRIGFATOP_UINT16##_FUNC_, \
    TRIGFATOP_INT32##_FUNC_, \
    TRIGFATOP_UINT32##_FUNC_, \
    TRIGFATOP_INT64##_FUNC_, \
    TRIGFATOP_UINT64##_FUNC_, \
    TRIGFATOP_INT128##_FUNC_, \
    TRIGFATOP_UINT128##_FUNC_, \
    TRIGFATOP_FLOAT##_FUNC_, \
    TRIGFATOP_DOUBLE##_FUNC_, \
    TRIGFATOP_LONGDOUBLE##_FUNC_ 

PyUFuncGenericFunction g_UFuncTrigLUT[TRIG_OPERATION::TRIG_LAST][ATOP_LAST] =
{
{DEF_TRIG_USTUB_NAME(0)},
{DEF_TRIG_USTUB_NAME(1)},
{DEF_TRIG_USTUB_NAME(2)},
{DEF_TRIG_USTUB_NAME(3)},
{DEF_TRIG_USTUB_NAME(4)},
{DEF_TRIG_USTUB_NAME(5)},
{DEF_TRIG_USTUB_NAME(6)},
{DEF_TRIG_USTUB_NAME(7)},
{DEF_TRIG_USTUB_NAME(8)},
{DEF_TRIG_USTUB_NAME(9)},
{DEF_TRIG_USTUB_NAME(10)},
{DEF_TRIG_USTUB_NAME(11)},
{DEF_TRIG_USTUB_NAME(12)},
{DEF_TRIG_USTUB_NAME(13)},
{DEF_TRIG_USTUB_NAME(14)},
{DEF_TRIG_USTUB_NAME(15)},
{DEF_TRIG_USTUB_NAME(16)},
{DEF_TRIG_USTUB_NAME(17)},
{DEF_TRIG_USTUB_NAME(18)},
{DEF_TRIG_USTUB_NAME(19)},
{DEF_TRIG_USTUB_NAME(20)},
};



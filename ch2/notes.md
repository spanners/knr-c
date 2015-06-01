Foo
===

Types, Operators and Expressions
================================

Variables and constants are the basic data objects manipulated in a
program. Declarations list the variables to be used, and state what type
they have and perhaps what their initial values are. Operators specify
what is to be done to them. Expressions combine variables and constants
to produce new values. The type of an object determines the set of
values it can have and what operations can be performed on it. These
building blocks are the topics of this chapter.

The ANSI standard has made many small changes and additions to basic
types and expressions. There are now `signed` and `unsigned` forms of
all integer types, and notations for unsigned constants and hexadecimal
character constants. Floating–point operations may be done in
single–precision; there is also a `long double` type for extended
precision. String constants may be concatenated at compile time.
Enumerations have become part of the language, formalizing a feature of
long standing. The rules for automatic coercions among arithmetic types
have been augmented to handle the richer set of types.

Variable Names
--------------

Although we didn’t say so in Chapter 1, there are some restrictions on
the names of variables and symbolic constants. Names are made up of
letters and digits; the first character must be a letter. The underscore
“\_” counts as a letter; it is sometimes useful for improving the
readability of long variable names. Don’t begin variable names with
underscore, however, since library routines often use such names. Upper
case and lower case letters are distinct, so `x` and `X` are two
different names. Traditional C practice is to use lower case for
variable names, and all upper case for symbolic constants.

At least the first 31 characters of an internal name are significant.
For function names and external variables, the number may be less than
31, because external names may be used by assemblers and loaders over
which the language has no control. For external names, the standards
guarantees uniqueness only for 6 characters and a single case. Keywords
like `if`, `else`, `int`, `float`, etc., are reserved: you can’t use
them as variable names. They must be in lower case.

It’s wise to choose variable names that are related to the purpose of
the variable, and that are unlikely to get mixed up typographically. We
tend to use short names for local variables, especially loop indices,
and longer names for external variables.

Data Types and Sizes
--------------------

There are only a few basic data types in C:

  ------------ -----------------------------------------------------
  `char`       a single bye, capable of holding one character in the
               local character set.

  `int`        an integer, typically reflecting the natural size of
               integers on the host machine.

  `float`      single–precision floating point.

  `double`     double–precision floating point.
  ------------ -----------------------------------------------------

In addition, there are a number of qualifiers that can be applied to
these basic types. `short` and `long` apply to integers:

~~~~ {.c}
short int sh;
long int counter;
~~~~

The word `int` can be omitted in such declarations, and typically is.

The intent is that `short` and `long` should provide different lengths
of integers where practical; `int` will normally be the natural size for
a particular machine. `short` is often 16 bits, `long` 32 bits, and
`int` either 16 or 32 bits. Each compiler is free to choose appropriate
sizes for its own hardware, subject only to the restriction that
`short`s and `int`s are at least 16 bits, `long`s are at least 32 bits,
and `short` is no longer than `int`, which is no longer than `long`.

The qualifier `signed` or `unsigned` may be applied to `char` or any
integer. `unsigned` numbers are always positive or zero, and obey the
laws of arithmetic modulo 2^$n$^, where $n$ is the number of bits in the
type. So, for instance, if `char`s are 8 bits, `unsigned char` variables
have values between 0 and 255, while `signed char`s have values between
-128 and 127 (in a two’s complement machine). Whether plain `char`s are
signed or unsigned is machine–dependent but printable characters are
always positive.

The type `long double` specifies extended–precision floating point. As
with integers, the sizes of floating–point objects are
implementation–defined; `float`, `double` and `long double` could
represent one, two or three distinct sizes.

The standard headers `<limits.h>` and `<float.h>` contain symbolic
constants for all of these sizes, along with other properties of the
machine and compiler. These are discussed in Appendix B.

**Exercise 2-1.** Write a program to determine the ranges of `char`,
`short`, `int`, and `long` variables, both `signed` and `unsigned`, by
printing the appropriate values from standard headers and by direct
computation. Harder if you compute them: determine the ranges of the
various floating point–types.

Constants
---------

An integer constant like `1234` is an `int`. A `long` constant is
written with a terminal `l` (ell) or `L`, as in `123456789L`; an integer
too big to fit into an `int` will also be taken as a `long`. Unsigned
constants are written with a terminal `u` or `U`, and the suffix `ul` or
`UL` indicates `unsigned long`.

Floating–point constants contain a decimal point (`123.4`) or an
exponent (`1e-2`) or both; their type is `double`, unless specified in
octal or hexadecimal instead of decimal. A leading `0` (zero) or an
integer constant means octal; a leading `0x` or `0X` means hexadecimal.
For example, decimal 31 can be written `037` in octal and `0x1f` or
`0X1F` in hex. Octal and hexadecimal constants may also be followed by
`L` to make them `long` and `U` to make them `unsigned`: `0XFUL` is an
`unsigned long` constant with value 15 decimal.

A *character constant* is an integer, written as one character within
single quotes, such as `'x'`. The value of a character constant is the
numeric value of the character in the machine’s character set. For
example, in the ASCII character set the character constant `'0'` has the
value 48, which is unrelated to the numeric value `0`. If we write `'0'`
instead of a numeric value like 48 that depends on character set, the
program is independent of the particular value and is easier to read.
Character constants participate in numeric operations, just as any other
integers, although they are most often used in comparisons with other
characters.

Certain characters can be represented in character and string constants
by escape sequences like `\n` (newline); the sequences look like two
characters but represent only one. In addition, an arbitrary byte–sized
bit pattern can be specified by

> ‘\\*ooo*’

where *ooo* is one to three octal digits (0…7) or by

> ‘\\`x`*hh*’

where *hh* is one or more hexadecimal digits (0..9, a…f, A..F). So we
might write

~~~~ {.c}
#define VTAB '\013'    /* ASCII vertical tab */
#define BELL '\007'    /* ASCII bell character */
~~~~

or, in hexadecimal,

~~~~ {.c}
#define VTAB '\xb'    /* ASCII vertical tab */
#define BELL '\x7'    /* ASCII bell character */
~~~~

The complete set of escape sequences is

  ------ ------------------------ ---------- --------------------
  `\a`   alert (bell) character   `\\`       backslash
  `\b`   backspace                `\?`       question mark
  `\f`   formfeed                 `\'`       single quote
  `\n`   newline                  `\"`       double quote
  `\r`   carriage return          `\`*ooo*   octal number
  `\t`   horizontal tab           `\x`*hh*   hexadecimal number
  `\v`   vertical tab                        
  ------ ------------------------ ---------- --------------------

The character constant `\0` represents the character with value zero,
the null character. `\0` is often written instead of 0 to emphasize the
character nature of some expression, but the numeric value is just 0.

A *constant expression* is an expression that involves only constants.
Such expressions may be evaluated during compilation rather than
run–time, and accordingly may be used in any place that a constant can
occur, as in

~~~~ {.c}
#define MAXLINE 1000
char line[MAXLINE+1];
~~~~

or

~~~~ {.c}
#define LEAP 1 /* in leap years */
int days[31+28+LEAP+31+30+31+30+31+31+30+31+30+31];
~~~~

A *string constant*, or *string literal*, is a sequence of zero or more
characters surrounded by double quotes, as in

~~~~ {.c}
"I am a string"
~~~~

or

~~~~ {.c}
"" /* the empty string */
~~~~

#include <stdio.h>

namespace Callbacks
{

    /* To pass a function in parameter, we use this odd syntax because of the conflict with the Forward Declaration Syntax */
    /* int (*operation)(void *context, int a, int b) */
    int do_math(void *context, int (*operation)(void *context, int a, int b), int a, int b)
    {
        return operation(context, a, b);
    }

    class Operations
    {
    public:
        int sub(int a, int b)
        {
            return a - b;
        }

        int add(int a, int b)
        {
            return a + b;
        };

        static int cast_add_callback(void *context, int a, int b)
        {
            /* reinterpreter_cast:
            /* It is used to convert a pointer of some data type into a pointer of another data type,
            even if the data types before and after conversion are different.*/
            return reinterpret_cast<Operations *>(context)->add(a, b);
        };

        static int cast_sub_callback(void *context, int a, int b)
        {
            return reinterpret_cast<Operations *>(context)->sub(a, b);
        };
    };
}

using namespace Callbacks;

int main(void)
{

    Operations *op = new Operations();

    int value = do_math(op, Operations::cast_sub_callback, 2, 2);

    printf("%d ", value);

    return 0;
}

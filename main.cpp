#include "stack.h"
#include <unistd.h>

const size_t BASE_CAP = 100;
const int NUM_OF_TESTS = 3;

int main ()
{
    FILE *file = fopen ("output.txt", "w");

    Test1 (file);
    fflush (file);

    Test2 (file);
    fflush (file);

    Test3 (file);
    fclose (file);

    return 0;
}

int Test1 (FILE *file)
{
    struct VStack *vstk = nullptr;
    struct LStack *lstk = nullptr;

    long long n = 0;

    int x = 0;
    int i = 0;
    int j = 0;

    double time1 = 0;
    double time2 = 0;

    double avg_vtime = 0;
    double avg_ltime = 0;

    srand (time (NULL));

    for (int test_num = 1; test_num <= NUM_OF_TESTS; test_num++)
    {
        printf ("test 1.%dv\n", test_num);
        vstk = VStackCtor (BASE_CAP, sizeof (int));

        n = pow (10, 6);

        time1 = (double) clock() / CLOCKS_PER_SEC;

        for (i = 0; i < pow (10, 6); i++)
        {
            x = rand ();
            VPush (vstk, &x);
        }

        for (i = 0; i < 9; i++)
        {
            for (j = 0; j < n / 2; j++) VPop (vstk);

            for (j = 0; i < n / 4; j++)
            {
                x = rand ();
                VPush (vstk, &x);
            }

            n -= n / 4;
        }

        time2 = (double) clock() / CLOCKS_PER_SEC;

        fprintf (file, "\nvstk test1 #%d:\t%lfs", test_num, time2 - time1);

        avg_vtime += time2 - time1;

        VStackDtor (vstk);
    }

    for (int test_num = 1; test_num <= NUM_OF_TESTS; test_num++)
    {
        printf ("test 1.%dl\n", test_num);
        lstk = LStackCtor (sizeof (int));

        n = pow (10, 6);

        time1 = (double) clock() / CLOCKS_PER_SEC;

        for (i = 0; i < pow (10, 6); i++)
        {
            x = rand ();
            LPush (lstk, &x);
        }

        for (i = 0; i < 9; i++)
        {
            for (j = 0; j < n / 2; j++) LPop (lstk);

            for (j = 0; i < n / 4; j++)
            {
                x = rand ();
                LPush (lstk, &x);
            }

            n -= n / 4;
        }

        time2 = (double) clock() / CLOCKS_PER_SEC;

        fprintf (file, "\nlstk test1 #%d:\t%lfs", test_num, time2 - time1);

        avg_ltime += time2 - time1;

        LStackDtor (lstk);
    }

    fprintf (file, "\n\ntest 1:\navg vtime = %lf\n avg ltime = %lf\n", avg_vtime / NUM_OF_TESTS, avg_ltime / NUM_OF_TESTS);

    return 0;
}


int Test2 (FILE *file)
{
    struct VStack *vstk = nullptr;
    struct LStack *lstk = nullptr;

    long long n = 0;

    int x = 0;
    int i = 0;
    int j = 0;

    double time1 = 0;
    double time2 = 0;

    double avg_vtime = 0;
    double avg_ltime = 0;

    srand (time (NULL));

    for (int test_num = 1; test_num <= NUM_OF_TESTS; test_num++)
    {
        printf ("test 2.%dv\n", test_num);
        vstk = VStackCtor (BASE_CAP, sizeof (int));

        n = pow (10, 6);

        time1 = (double) clock() / CLOCKS_PER_SEC;

        for (i = 0; i < pow (10, 6); i++)
        {
            x = rand ();
            VPush (vstk, &x);
        }

        for (i = 0; i < 100; i++)
        {
            for (j = 0; j < 10000; j++) VPop (vstk);

            for (j = 0; i < 10000; j++)
            {
                x = rand ();
                VPush (vstk, &x);
            }
        }

        for (i = 0; i < 9; i++)
        {
            for (j = 0; j < n / 2; j++) VPop (vstk);

            for (j = 0; i < n / 4; j++)
            {
                x = rand ();
                VPush (vstk, &x);
            }

            n -= n / 4;
        }

        for (i = 0; i < 100; i++)
        {
            for (j = 0; j < 10000; j++) VPop (vstk);

            for (j = 0; i < 10000; j++)
            {
                x = rand ();
                VPush (vstk, &x);
            }
        }

        time2 = (double) clock() / CLOCKS_PER_SEC;

        fprintf (file, "\nvstk test2 #%d:\t%lfs", test_num, time2 - time1);

        avg_vtime += time2 - time1;

        VStackDtor (vstk);
    }

    for (int test_num = 1; test_num <= NUM_OF_TESTS; test_num++)
    {
        printf ("test 2.%dl\n", test_num);
        lstk = LStackCtor (sizeof (int));

        n = pow (10, 6);

        time1 = (double) clock() / CLOCKS_PER_SEC;

        for (i = 0; i < pow (10, 6); i++)
        {
            x = rand ();
            LPush (lstk, &x);
        }

        for (i = 0; i < 100; i++)
        {
            for (j = 0; j < 10000; j++) LPop (lstk);

            for (j = 0; i < 10000; j++)
            {
                x = rand ();
                LPush (lstk, &x);
            }
        }

        for (i = 0; i < 9; i++)
        {
            for (j = 0; j < n / 2; j++) LPop (lstk);

            for (j = 0; i < n / 4; j++)
            {
                x = rand ();
                LPush (lstk, &x);
            }

            n -= n / 4;
        }

        for (i = 0; i < 100; i++)
        {
            for (j = 0; j < 10000; j++) LPop (lstk);

            for (j = 0; i < 10000; j++)
            {
                x = rand ();
                LPush (lstk, &x);
            }
        }

        time2 = (double) clock() / CLOCKS_PER_SEC;

        fprintf (file, "\nlstk test2 #%d:\t%lfs", test_num, time2 - time1);

        avg_ltime += time2 - time1;

        LStackDtor (lstk);
    }

    fprintf (file, "\n\ntest 2:\navg vtime = %lf\n avg ltime = %lf\n", avg_vtime / NUM_OF_TESTS, avg_ltime / NUM_OF_TESTS);

    return 0;
}

int Test3 (FILE *file)
{
    struct VStack *vstk = nullptr;
    struct LStack *lstk = nullptr;

    int x = 0;
    int i = 0;

    double time1 = 0;
    double time2 = 0;

    double avg_vtime = 0;
    double avg_ltime = 0;

    srand (time (NULL));

    for (int test_num = 1; test_num <= NUM_OF_TESTS; test_num++)
    {
        printf ("test 3.%dv\n", test_num);
        vstk = VStackCtor (BASE_CAP, sizeof (int));

        for (i = 0; i < pow (10, 6); i++)
        {
            x = rand ();
            VPush (vstk, &x);
        }

        time1 = (double) clock() / CLOCKS_PER_SEC;

        for (i = 0; i < pow (10, 6); i++)
        {
            if (rand () % 2)
            {
                x = rand ();
                VPush (vstk, &x);
            }
            else VPop (vstk);
        }

        time2 = (double) clock() / CLOCKS_PER_SEC;

        fprintf (file, "\nvstk test3 #%d:\t%lfs", test_num, time2 - time1);

        avg_vtime += time2 - time1;

        VStackDtor (vstk);
    }

    for (int test_num = 1; test_num <= NUM_OF_TESTS; test_num++)
    {
        printf ("test 3.%dl\n", test_num);
        lstk = LStackCtor (sizeof (int));

        for (i = 0; i < pow (10, 6); i++)
        {
            x = rand ();
            LPush (lstk, &x);
        }

        time1 = (double) clock() / CLOCKS_PER_SEC;

        for (i = 0; i < pow (10, 6); i++)
        {
            if (rand () % 2)
            {
                x = rand ();
                LPush (lstk, &x);
            }
            else LPop (lstk);
        }

        time2 = (double) clock() / CLOCKS_PER_SEC;

        fprintf (file, "\nlstk test3 #%d:\t%lfs", test_num, time2 - time1);

        avg_ltime += time2 - time1;

        LStackDtor (lstk);
    }

    fprintf (file, "\n\ntest 3:\navg vtime = %lf\n avg ltime = %lf\n", avg_vtime / NUM_OF_TESTS, avg_ltime / NUM_OF_TESTS);

    return 0;
}
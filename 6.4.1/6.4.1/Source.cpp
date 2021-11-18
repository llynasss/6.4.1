#include <iostream> 

#include <iomanip> 

#include <time.h> 



using namespace std;



void create(double* a, int n, int l, int h);

void print(double* a, int n);

double sum(double* a, int n);

double dob_p(double* a, int n);

int min_ip(double* a, int n);

int max_ip(double* a, int n);

void sort(double* a, int n);



int main() {

    srand((unsigned)time(NULL));



    int n;

    int l = -10;

    int h = 10;

    int k;

    double s;

    double d;



    cout << "n = "; cin >> n;

    double* a = new double[n];



    create(a, n, l, h);



    print(a, n);



    s = sum(a, n);



    d = dob_p(a, n);



    sort(a, n);



    print(a, n);



    cout << endl << "| s = " << s << " |";

    cout << endl << "| d = " << d << " |";



    return 0;

}







void create(double* a, int n, int l, int h) {

    for (int i = 0; i < n; i++) {

        a[i] = ((((double)rand()) / (double)RAND_MAX) * ((double)h - (double)l)) + (double)l;

    }

}



void print(double* a, int n) {

    cout << "| a |";

    for (int i = 0; i < n; i++) {

        cout << setw(7) << setprecision(6) << a[i] << " |";

    }

    cout << endl;

}



double sum(double* a, int n) {

    double s = 0;

    for (int i = 0; i < n; i++) {

        if (a[i] < 0) {

            s += a[i];

        }

    }

    return s;

}



double dob_p(double* a, int n) {

    double dob = 1;

    int tmp;

    int i = min_ip(a, n);

    int j = max_ip(a, n);



    cout << "| i min = " << i << " |";

    cout << endl << "| i max = " << j << " |" << endl;



    if (i > j) {

        tmp = i;

        i = j;

        j = tmp;

    }



    if (i + 1 - j == 0) {

        return -1;

    }



    for (int p = i + 1; p < j; p++) {

        dob *= a[p];

    }

    return dob;

}



int min_ip(double* a, int n) {

    double min_a = a[0];

    int min_i = 0;

    for (int i = 0; i < n; i++) {

        if (a[i] < min_a) {

            min_a = a[i];

            min_i = i;

        }

    }

    return min_i;

}



int max_ip(double* a, int n) {

    double max_a = a[0];

    int max_i = 0;

    for (int i = 0; i < n; i++) {

        if (a[i] > max_a) {

            max_a = a[i];

            max_i = i;

        }

    }

    return max_i;

}



void sort(double* a, int n) {

    for (int i = 0; i < n - 1; i++)

    {

        double min = a[i];

        int imin = i;

        for (int j = i + 1; j < n; j++)

            if (min > a[j])

            {

                min = a[j];

                imin = j;

            }

        a[imin] = a[i];

        a[i] = min;

    }

}
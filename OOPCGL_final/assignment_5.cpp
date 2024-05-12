#include <iostream>
#include <string>
using namespace std;

template <typename T>

void sort(T arr[], int n)
{
    T key;
    for(int i = 0; i<n; i++)
    {
        key = arr[i];
        int j = i - 1;
        while(j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

template <typename T1>

void selection_sort(T1 arr[], int n)
{
    T1 temp;
    int idx;
    for(int i = 0;i < n-1;i++)
    {
        idx = i;
        for(int j = i+1; j < n; j++)
        {
            if(arr[j] < arr[idx])
                idx = j;
        }
        temp = arr[i];
        arr[i] = arr[idx];
        arr[idx] = temp;
    }
}

int main()
{
    int n;   //,m;
	cout<<"Enter No. of Elements for float array A:";
	cin>>n;
	// cout<<"Enter No. of Elements for float array B:";
	// cin>>m;

	float *a = new float[n];
	//float *b = new float[m];

	cout<<"Enter " << n << " Integers:"<<endl;
	for (int i=0; i<n; i++)
    {
		cin>>a[i];
	}

	// cout<<"Enter "<<m<<" Floats:"<<endl;
	// for (int i=0; i<m; i++)
    // {
	// 	cin >> b[i];
	// }

    for(int i = 0;i<n;i++){
        cout<<"{"<<a[i]<<"}";
    }

    cout<<"After sorting. using insertion"<<endl;
    sort<float>(a,n);

    for(int p = 0;p<n;p++){
        cout<<"{"<<a[p]<<"}";
    }

    cout<<"After sorting. using selection"<<endl;
    selection_sort<float>(a,n);

    for(int p = 0;p<n;p++){
        cout<<"{"<<a[p]<<"}";
    }
    return 1;
}


// void selection_sort(T arr[], int n)
// {
//     T temp;
//     int idx;
//     for(int i = 0;i < n-1;i++)
//     {
//         idx = i;
//         for(int j = i+1; j < n; j++)
//         {
//             if(arr[j] < arr[idx])
//                 idx = j;
//         }
//         temp = arr[i];
//         arr[i] = arr[idx];
//         arr[idx] = temp;
//     }
// }
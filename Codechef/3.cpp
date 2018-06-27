#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
	// your code goes here
	#ifdef __APPLE__
		freopen("input.txt", "r", stdin);
	#endif
	long int t,n,i,j,k;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    long long int arr[n];
	    for(i=0;i<n;i++)
	    {
	        cin>>arr[i];
	        if(arr[i]<0)
	            arr[i]*=-1;
	    }
	    for(i=1;i<n-1;i++)
	    {
	        if(arr[i]<arr[i-1] && arr[i]<arr[i+1])
	        {
	            arr[i]*=-1;
	            i++;
	        }
	    }
	    if(arr[0]<arr[1])
	        arr[0]*=-1;
	    if(arr[n-1]<arr[n-2])
	        arr[n-1]*=-1;
	    long long int sum=0,flag[n]={0};
	    for(i=0;i<n-2;i++)
	    { 
	        if(arr[i]<0 && arr[i+2]<0)
	        {
	            j=i;
	            sum=(((arr[i]+arr[i+1]))+arr[i+2]);
	            while(sum<1 && j<n-2)
	            {
	                j+=2;
	                sum=(((arr[j]+arr[j+1]))+arr[j+2]);
	            }
	            if(j>n)
	                j-=2;
	            if(j>i)
	            {
    	            long long int tmp1=0,tmp2=0,a[((j-i)/4)+1],b[((j-i-2)/4)+1],c1=-1,c2=-1;
    	            for(k=i;k<=j;k+=4)
    	            {
    	                a[++c1]=((-1)*arr[k]);
    	            }
    	            for(k=i+2;k<=j;k+=4)
    	            {
    	                b[++c2]=((-1)*arr[k]);
    	            }
    	            for(k=0;k<=c2;k++)
    	            {
    	                a[k]=a[k]-b[k];
    	            }
    	            for(k=0;k<=c1;k++)
    	                tmp1+=a[k];
    	            if(tmp1<=0)
    	            {
    	                for(k=i;k<=j;k+=4)
    	                    arr[k]*=-1;
    	            }
    	            else
    	            {
    	                for(k=i+2;k<=j;k+=4)
    	                    arr[k]*=-1;
    	            }
    	            
    	            i=j+1;
	            }
	        }
	    }
	        
	    for(i=0;i<n;i++)
	        cout<<arr[i]<<" ";
	    cout<<endl;
	}
	return 0;
}
import java.util.*;

public class Sample{

    private static int n;
    public static void sort(int arr[]){
        hpsort(arr);
        for(int i=n;i>0;i--){
            swap(arr,0,i);
            n=n-1;
            heap(arr,0);
        }
    }

    public static void hpsort(int arr[]){
        n=arr.length-1;
        for(int i=n/2;i>=0;i--){
            heap(arr,i);
        }
    }
    public static void heap(int arr[],int i){
        int left = 2*i;
        int right = 2*i+1;
        int max = i;
        if(left <= n && arr[left] > arr[i])
            max=left;
        if(right <= n && arr[right] > arr[max])
            max=right;
        if(max != i){
            swap(arr,i,max);
            heap(arr, max);
        }
    }
    public static void swap(int arr[], int i, int j){
        int tmp=arr[i];
        arr[i]=arr[j];
        arr[j]=tmp;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of elements :");
        int n = sc.nextInt();
        int arr[] = new int[n];
        System.out.println("Enter the elements");
        for(int i=0; i<n;i++)
            arr[i]=sc.nextInt();
        sort(arr);
        System.out.println("Ater Sorting :");
        for(int i=0; i<n; i++)
            System.err.println(arr[i]+" ");
        sc.close();
    }
}











// import java.util.*;

// public class Sample{
    
//     public static void hpsort(int[] array){
//         int n = array.length;

//         for (int i=n/2-1;i>=0;i--){
//             hp(array,n,i);
//         }

//         for (int i=n-1;i>0;i--){
//             int temp=array[0];
//             array[0]=array[i];
//             array[i]=temp;
//             hp(array,i,0);
//         }
//     }

//     static void hp(int[] array,int n,int i){
//         int large=i;
//         int left=2*i+1;
//         int right=2*i+2;

//         if(left<n && array[left] > array[large]){
//             large=left;
//         }
//         if(right<n && array[right]>array[large]){
//             large=right;
//         }
//         if(large!=i){
//             int swap=array[i];
//             array[i]=array[large];
//             array[large]=swap;
//             hp(array, n, large);
//         }
//     }

//     static void print(int[] array){
//         for (int value : array){
//             System.out.println(value+" ");
//         }
//     }

//     public static void main(String[] args){
//         Scanner sc = new Scanner(System.in);

//         System.out.println("Enter the number of elements :");
//         int size= sc.nextInt();
//         int[] array = new int[size];
//         System.out.println("Enter the elements :");
//         for(int i=0;i<size;i++){
//             array[i]=sc.nextInt();
//         }
//         sc.close();
//         hpsort(array);
//         System.out.println("Sorted array :");
//         print(array);
//     }
// }
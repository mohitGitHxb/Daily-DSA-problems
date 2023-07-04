https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

TC O(NlogN)
SC O(1)

bool isPossible(int arr[], int n, int m, int mid){
        int cnt = 1;
        int pageSum =0;
        for(int i =0; i<n; i++){
        if(pageSum + arr[i] <= mid){
            pageSum += arr[i];
        }
        else{
            cnt++;
            if(cnt > m || mid< arr[i]){
                return false;
            }
            pageSum =arr[i];
        }
        }
        return true;
    }
    
    
    
    int findPages(int A[], int N, int M) 
    {
        //code here
        int s =0;
        int sum =0;
        int ans = -1;
        if(N<M){
            return -1;
        }
        for(int i =0; i<N; i++){
            sum += A[i];
        }
        int e = sum;
        int mid = s+(e-s)/2;
        while(s<=e){
            if(isPossible(A, N, M, mid)){
                ans = mid;
                e = mid -1;
            }
            else{
                s = mid +1;
            }
            mid = s+(e-s)/2;
        }
        return ans;
    }


explaination:

The findPages function is the main function that solves the problem using binary search.

It takes an array A representing the number of pages in each book, the total number of books N, and the number of students M.
It initializes variables s and e to represent the start and end of the search range, respectively. It also initializes sum to store the total number of pages in all books.
If the number of books N is less than the number of students M, it means there are fewer books than the number of students, so it is not possible to allocate the books evenly. In this case, it returns -1.
It performs a binary search to find the minimum possible maximum number of pages that can be allocated to a student. The search is performed until s is less than or equal to e.
In each iteration, it calls the isPossible function to check if it is possible to allocate books with the current mid value. If it is possible, it updates the answer ans to mid and narrows down the search range by updating e to mid - 1.
If it is not possible to allocate books with the current mid value, it updates s to mid + 1 to search for larger mid values.
Finally, it returns the minimum possible maximum number of pages that can be allocated to a student (ans).
The isPossible function is a helper function that checks if it is possible to allocate books with the given constraints.

It takes an array arr representing the number of pages in each book, the total number of books n, the number of students m, and the maximum number of pages mid that can be allocated to a student.
It iterates through each book and checks if the current page sum pageSum plus the pages of the current book arr[i] is less than or equal to mid.
If it is, it means the current student can be assigned this book, so the pageSum is updated accordingly.
If the pageSum exceeds mid, it means a new student needs to be assigned. The cnt variable is incremented, and if cnt exceeds m or mid is less than the pages of the current book, it returns false, indicating it is not possible to allocate the books within the given constraints.
After iterating through all books, if no invalid allocation is found, it returns true, indicating it is possible to allocate the books.

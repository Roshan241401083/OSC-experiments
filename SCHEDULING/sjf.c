#include <stdio.h>
#include <limits.h>
int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int at[n], bt[n], tat[n], wt[n], done[n];
    for(int i = 0; i < n; i++)
    {
        printf("Enter Arrival Time and Burst Time for P%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        done[i] = 0;
    }
    int completed = 0, completionTime = 0;
    float avgtat = 0, avgwt = 0;
    while(completed < n)
    {
        int idx = -1;
        int minBT = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            if(at[i] <= completionTime && done[i] == 0)
            {
                if(bt[i] < minBT)
                {
                    minBT = bt[i];
                    idx = i;
                }
            }
        }
        if(idx != -1)
        {
            if(completionTime < at[idx])
                completionTime = at[idx];
            completionTime += bt[idx];
            tat[idx] = completionTime - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            done[idx] = 1;
            completed++;
        }
        else
        {
            completionTime++;
        }
    }
    printf("\nProcess\tAT\tBT\tTAT\tWT\n");
    for(int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], tat[i], wt[i]);
        avgtat += tat[i];
        avgwt += wt[i];
    }
    printf("\nAverage Turnaround Time: %.2f\n", avgtat / n);
    printf("Average Waiting Time: %.2f\n", avgwt / n);
    return 0;
}

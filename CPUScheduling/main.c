#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  int processId;
  int burstTime;
  int arrivalTime;
  int waitingTime;
  int turnaroundTime;
  int priority;
} process;

typedef struct
{
  process *processes;
  int front, back;
  int n;
} Queue;

void initQueue(Queue *Q, int n)
{
  Q->front = 0;
  Q->back = -1;
  Q->processes = calloc(n + 1, sizeof(process));
  Q->n = n + 1;
}

int isFull(Queue Q)
{
  return ((Q.back + 2) % Q.n) == Q.front;
}

int isEmpty(Queue Q)
{
  int val = 0;
  if (Q.n != 0)
    val = ((Q.back + 1) % Q.n) == Q.front;

  return val;
}

void enqueue(Queue *Q, process proc)
{

  if (!isFull(*Q))
  {
    Q->back = (Q->back + 1) % Q->n;
    Q->processes[Q->back] = proc;
  }
}

process dequeue(Queue *Q)
{
  process p = {-1, -1};

  if (!isEmpty(*Q))
  {
    p = Q->processes[Q->front];
    Q->front = (Q->front + 1) % Q->n;
  }
  return p;
}

void FCFSalgo(process processes[], int n)
{
  int WT, ms, x;
  float AWT, ATAT;

  AWT = ATAT = ms = 0;
  for (x = 0; x < n; x++)
  {
    AWT += ms;
    ms += processes[x].burstTime;
    ATAT += ms;
    printf("(p%d: BT:%d ms:%d) -> ", processes[x].processId, 0, ms);
  }

  AWT /= n;
  ATAT /= n;

  printf("\nAverage Waiting Time: %.3g ms\n", AWT);
  printf("Average Turnaround Time: %.2g ms\n", ATAT);
}

void populateQueue(Queue *Q, process processes[], int n)
{
  int x;
  process p, tmp;

  for (x = 0; x < n; x++)
  {
    tmp = processes[x];
    p.arrivalTime = tmp.arrivalTime;
    p.burstTime = tmp.burstTime;
    p.processId = tmp.processId;
    enqueue(Q, p);
  }
}

void RRalgo(process processes[], int n, int TQ)
{
  int ms, totalWaitingTime, remainingTime;
  process tmp[n + 1], *curr;
  Queue circQueue;
  process prev = {-1, 0};

  initQueue(&circQueue, n);
  populateQueue(&circQueue, processes, n);

  totalWaitingTime = ms = 0;
  while (!isEmpty(circQueue))
  {
    curr = &circQueue.processes[circQueue.front];
    remainingTime = curr->burstTime > TQ ? curr->burstTime - TQ : 0;

    if (remainingTime == 0 || circQueue.back == circQueue.front)
    {
      totalWaitingTime += ms;
      ms += curr->burstTime;
      if (circQueue.back == circQueue.front)
      {
        remainingTime = 0;
      }
      dequeue(&circQueue);
      curr->burstTime = remainingTime;
    }
    else
    {
      if (prev.processId != curr->processId)
        totalWaitingTime -= TQ;
      ms += TQ;
      curr->burstTime = remainingTime;
      prev = dequeue(&circQueue);
      enqueue(&circQueue, prev);
    }
    printf("(p%d: BT:%d ms:%d) -> ", curr->processId, curr->burstTime, ms);
  }
  printf("\nAverage Waiting Time: %.3g ms", (float)totalWaitingTime / n);
  printf("\nAverage Turnaround Time: %.2g ms\n", (float)ms / n);
}

void pSJFalgo(int n, process processes[])
{
  process temp[n];
  int max = 0, large = 0, count = 0, t = 0, short_P, WTarr[n];
  float total_WT = 0, total_TAT = 0, Avg_WT = 0, Avg_TAT = 0;

  for (int i = 0; i < n; i++)
  {
    temp[i] = processes[i];
    WTarr[i] = temp[i].burstTime;
    if (temp[i].burstTime > large)
    {
      large = temp[i].burstTime;
      max = i;
    }
  }

  printf("\n");
  for (t = 0; count < n; t++)
  {
    short_P = max;

    for (int i = 0; i < n; i++)
    {
      if (temp[i].burstTime < temp[short_P].burstTime && (temp[i].arrivalTime <= t && temp[i].burstTime > 0))
      {
        short_P = i;
      }
    }
    temp[short_P].burstTime -= 1;

    if (temp[short_P].burstTime == 0)
    {
      count++;
      temp[short_P].waitingTime = t - temp[short_P].arrivalTime - WTarr[short_P];
      temp[short_P].turnaroundTime = t - temp[short_P].arrivalTime;

      total_WT += temp[short_P].waitingTime;
      total_TAT += temp[short_P].turnaroundTime;

      printf("(p%d: BT:%d ms:%d) -> ", temp[short_P].processId, temp[short_P].burstTime, temp[short_P].waitingTime);
    }
  }

  Avg_WT = total_WT / n;
  Avg_TAT = total_TAT / n;

  printf("\nAverage Waiting Time: %.2f ms", Avg_WT);
  printf("\nAverage Turnaround Time: %.2f ms\n", Avg_TAT);
}

void npSJFalgo(int n, process processes[])
{
  process temp[n];
  int i, j, t, p[n], bt[n], wt[n], tat[n];
  float awt = 0, atat = 0;

  for (i = 0; i < n; i++)
  {
    temp[i] = processes[i];
  }

  for (i = 0; i < n; i++)
  {
    p[i] = temp[i].processId;
    bt[i] = temp[i].burstTime;
  }

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n - 1; j++)
    {
      if (bt[j] > bt[j + 1])
      {
        t = bt[j];
        bt[j] = bt[j + 1];
        bt[j + 1] = t;

        t = p[j];
        p[j] = p[j + 1];
        p[j + 1] = t;
      }
    }
  }

  printf("\n");
  for (i = 0; i < n; i++)
  {
    wt[i] = 0;
    tat[i] = 0;
    for (j = 0; j < i; j++)
    {
      wt[i] += bt[j];
    }
    tat[i] = wt[i] + bt[i];
    awt += wt[i];
    atat += tat[i];

    printf("(p%d: BT:%d ms:%d) -> ", p[i], bt[i], wt[i]);
  }

  awt /= n;
  atat /= n;

  printf("\nAverage Waiting Time: %.2f ms", awt);
  printf("\nAverage Turnaround Time: %.2f ms\n", atat);
}

void swap(process processes[], int x, int z)
{
  process temp;
  temp = processes[x];
  processes[x] = processes[z];
  processes[z] = temp;
}

void priorityAlgo(process processes[], int n)
{
  int x, y, z, flip, totalBT, totalWT;
  float avgWT, avgTAT;

  totalBT = 0;
  totalWT = 0;
  avgWT = 0.0;
  avgTAT = 0.0;

  for (x = 0; x < n; x++)
  {
    flip = 0;
    z = x;
    for (y = x + 1; y < n; y++)
    {
      if (processes[z].priority > processes[y].priority)
      {
        z = y;
        flip = 1;
      }
      if (processes[z].priority == processes[y].priority && flip != 1)
      {
        if (processes[z].processId > processes[y].processId)
        {
          z = y;
        }
      }
    }
    if (z != x)
    {
      swap(processes, x, z);
    }
  }

  for (x = 0; x < n; x++)
  {
    totalBT += processes[x].burstTime;
    processes[x].turnaroundTime = totalBT;
    processes[x].waitingTime = totalWT;
    totalWT += processes[x].burstTime;
  }

  printf("%11s", "Process ID ");
  printf("%13s", "Burst Time ");
  printf("%14s", "Waiting Time ");
  printf("%11s", "Priority\n");

  for (x = 0; x < n; x++)
  {
    printf("%2d", processes[x].processId);
    printf("%13d", processes[x].burstTime);
    printf("%12d", processes[x].waitingTime);
    printf("%14d\n", processes[x].priority);
  }

  printf("\n");

  for (x = 0; x < n; x++)
  {
    avgWT += processes[x].waitingTime;
    avgTAT += processes[x].turnaroundTime;

    printf("(p%d: BT: %d ms: %d) ", processes[x].processId, processes[x].burstTime, processes[x].waitingTime);
    if (x < n - 1)
    {
      printf("-> ");
    }
  }

  avgWT /= n;
  avgTAT /= n;

  printf("\n\nAverage Waiting Time: %.2f ms", avgWT);
  printf("\nAverage Turnaround Time: %.2f ms", avgTAT);
}

int menuType()
{
  int val = 0;
  printf("Choose a type of CPU scheduling Algorithm:\n");
  printf("(Input 0 to end the program):\n");
  printf("1. Preemptive\n");
  printf("2. Non-preemptive\n");

  printf("selected: ");
  scanf("%d", &val);
  return val;
}

int menuAlgos()
{
  int val = 0;

  printf("Choose an algorithm \n");
  printf("(Input 0 to end the program):\n");

  printf("1. Shortest Job First\n");
  printf("2. Round-Robin Algorithm\n");
  printf("3. Priority Scheduling\n");
  printf("4. First-Come, First-Served\n");

  printf("selected: ");
  scanf("%d", &val);
  return val;
}

int getATInput()
{
  int in;
  printf("Arrival Time: ");
  scanf("%d", &in);
  return in;
}

int getBTInput()
{
  int in;
  printf("Burst Time: ");
  scanf("%d", &in);

  return in;
}

int getPInput()
{
  int in;
  printf("Priority: ");
  scanf("%d", &in);

  return in;
}

int getTQInput()
{
  int in;
  printf("Time Slice: ");
  scanf("%d", &in);

  return in;
}

void getInput(int opt, process p[], int n)
{
  int x;

  switch (opt)
  {
  case 1:
  {
    for (x = 0; x < n; x++)
    {
      printf("\nprocess %d\n", x);
      p[x].processId = x;
      p[x].burstTime = getBTInput();
      p[x].arrivalTime = getATInput();
    }
    printf("\n\nPreemptive Shortest Job First Algorithm\n\n");
    pSJFalgo(n, p);
    printf("\nNonpreemptive Shortest Job First Algorithm\n\n");
    npSJFalgo(n, p);
    break;
  }
  case 2:
  {
    int TQ = getTQInput();
    for (x = 0; x < n; x++)
    {
      printf("\nprocess %d\n", x);
      p[x].processId = x;
      p[x].burstTime = getBTInput();
    }
    printf("\n\nRound-Robin Algorithm\n\n");
    RRalgo(p, n, TQ);
    break;
  }
  case 3:
  {
    for (x = 0; x < n; x++)
    {
      printf("\nprocess %d\n", x);
      p[x].processId = x;
      p[x].burstTime = getBTInput();
      p[x].priority = getPInput();
    }
    printf("\n\nPriority Scheduling Algorithm\n\n");
    priorityAlgo(p, n);
    break;
  }
  case 4:
  {
    for (x = 0; x < n; x++)
    {
      printf("\nprocess %d\n", x);
      p[x].processId = x;
      p[x].burstTime = getBTInput();
    }
    printf("\nFirst-Come, First-Served\n\n");
    FCFSalgo(p, n);
    break;
  }
  }
}

int main()
{
  // process {processId, burstTime, arrivalTime}4
  process procs[] = {
      {1, 10, -1},
      {2, 29, -1},
      {3, 3, -1},
      {4, 7, -1},
      {5, 12, -1},
  };
  process procs2[] = {
      {1, 10, 0, 0, 0, 1},
      {2, 29, 0, 0, 0, 4},
      {3, 3, 0, 0, 0, 0},
      {4, 7, 0, 0, 0, 0},
      {5, 12, 0, 0, 0, 3},
  };
  int n = 5;

  int a, b, c;

  b = menuAlgos();
  printf("\n");

  printf("How many processes? ");
  scanf("%d", &c);
  printf("\n");

  process p[c];

  getInput(b, p, c);
}
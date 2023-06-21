# Shell

The above contains a folder having the implementation of a shell which can run the following UNIX commands.
Supported Commands :
1. cd
2. ls
3. help
4. exit
5. history
and a lot of other builtin commands.


To run the above folder :
I have used WSL(Windows Subsystem for Linux)

Steps to run :
1. using the bash terminal to clone the repository
2. open main.c in a code editor and run the command in terminal  gcc main.c -o main && "/mnt/c/Users/hp/Desktop/shell/"main
   (here /mnt/c/Users/hp/Desktop/shell/ is a path to Shell folder and  uses all the files in the folder shell for compilation , you can add path to this folder as in your device) , or You can directly press the run button over the main.c file 

Understanding shell from top down :
Three things done by shell in its lifetime.
Initialize: In this step, a typical shell would read and execute its configuration files. These change aspects of the shell’s behavior.
Interpret: Next, the shell reads commands from stdin (which could be interactive, or a file) and executes them.
Terminate: After its commands are executed, the shell executes any shutdown commands, frees up any memory, and terminates.

#**Basic Loop of a shell :**
**Read:** Read the command from standard input.
**Parse:** Separate the command string into a program and arguments.
**Execute:** Run the parsed command.

#**Reading and Parsing :**
In a system like a shell, one doesn't know the amount of text or characters coming in as input hence a line is read by first allocating some buffer space in the
heap memory using the malloc function, and then when it is filled we allocate a double sized memory than current one, this changes the amortized cost of each 
addition to O(1) as it is similar to vector implementation in c++.
When the line is taken as input it is then broken into parts such as command and arguements.

#**Core :**
The main function of shell is to start a process :
There are only two ways of starting processes on Unix. The first one is by being Init. When a Unix computer boots, its kernel is loaded. Once it is loaded and 
initialized, the kernel starts only one process, which is called Init. This process runs for the entire length of time that the computer is on, and it manages to
load up the rest of the processes that one need's for ones computer to be useful.

Since most programs aren’t Init, that leaves only one practical way for processes to get started: the fork() system call. When this function is called, the 
operating system makes a duplicate of the process and starts them both running. The original process is called the “parent”, and the new one is called the “child”.
fork() returns 0 to the child process, and it returns to the parent the process ID number (PID) of its child. In essence, this means that the only way for new 
processes is to start is by an existing one duplicating itself.

When one want to run a new process, one does’t just want another copy of the same program – one wants to run a different program. That’s what the exec() system 
call is all about. It replaces the current running program with an entirely new one. This means that when we call exec, the operating system stops the process, 
loads up the new program, and starts that one in its place. A process never returns from an exec() call (unless there’s an error).

With these two system calls, we have the building blocks for how most programs are run on Unix. First, an existing process forks itself into two separate ones. 
Then, the child uses exec() to replace itself with a new program. The parent process can continue doing other things, and it can even keep tabs on its children, 
using the system call wait().

The launch function takes the list of arguments that we created earlier. Then, it forks the process, and saves the return value. Once fork() returns, we actually 
have two processes running concurrently. The child process will take the first if condition (where pid == 0).

In the child process, we want to run the command given by the user. So, we use one of the many variants of the exec system call, execvp. The different variants of
exec do slightly different things. Some take a variable number of string arguments. Others take a list of strings. Still others let you specify the environment 
that the process runs with. This particular variant expects a program name and an array (also called a vector, hence the ‘v’) of string arguments (the first one 
has to be the program name). The ‘p’ means that instead of providing the full file path of the program to run, we’re going to give its name, and let the operating 
system search for the program in the path.

If the exec command returns -1 (or actually, if it returns at all), we know there was an error. So, we use perror to print the system’s error message, along with 
our program name, so users know where the error came from. Then, we exit so that the shell can keep running.

The second condition (pid < 0) checks whether fork() had an error. If so, we print it and keep going – there’s no handling that error beyond telling the user and 
letting them decide if they need to quit.

The third condition means that fork() executed successfully. The parent process will land here. We know that the child is going to execute the process, so the 
parent needs to wait for the command to finish running. We use waitpid() to wait for the process’s state to change. Unfortunately, waitpid() has a lot of options
(like exec()). Processes can change state in lots of ways, and not all of them mean that the process has ended. A process can either exit (normally, or with an
error code), or it can be killed by a signal. So, we use the macros provided with waitpid() to wait until either the processes are exited or killed. Then, the
function finally returns a 1, as a signal to the calling function that we should prompt for input again.

#**Builtins Supported** 
Some commands are built right into the shell for example , If you want to change directory, you need to use the function chdir(). The thing is, the current 
directory is a property of a process. So, if you wrote a program called cd that changed directory, it would just change its own current directory, and then 
terminate. Its parent process’s current directory would be unchanged. Instead, the shell process itself needs to execute chdir(), so that its own current directory
is updated. Then, when it launches child processes, they will inherit that directory too.

if there was a program named exit, it wouldn’t be able to exit the shell that called it. That command also needs to be built into the shell. Also, most shells are 
configured by running configuration scripts, like ~/.bashrc. Those scripts use commands that change the operation of the shell. These commands could only change
the shell’s operation if they were implemented within the shell process itself.


So, it makes sense that we need to add some commands like cd , exit , help , history in the shell itself.

The execute function calls a command if it is a builtin or creates another process if it is not.

For Implementing the History Command: A Linked List has been used which is made up of a user defined data type Node, Node contains a string that has the name of the command and a pointer to the next Node , the Last Node points to Null. The add_to_hist() is called to put the Node in Linked List, and when the history command is run in the shell, the Linked List is Printed.


Made By : Vardaan Dua                                                                                                                                                                

Student : Btech CSE - 2025 (IIT-R)                                                                                                                                                                                                

Enrollment Number : 21115155                                                                                                                                                                                                                                 

Email : v_dua@cs.iitr.ac.in

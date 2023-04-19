0x16. C - Simple Shell

# Background Context
Write a simple UNIX command interpreter.

# Tasks
0. Betty would be proud
1. Simple shell 0.1
2. Simple shell 0.2
3. Simple shell 0.3
4. Simple shell 0.4
5. Simple shell 1.0
6. Simple shell 0.1.1
7. Simple shell 0.2.1
8. Simple shell 0.4.1
9. setenv, unsetenv
10. cd
11. ;
12. && and ||
13. alias
14. Variables
15. Comments
16. File as input

# List of allowed functions and system calls

0. access (man 2 access)
1. chdir (man 2 chdir)
2. close (man 2 close)
3. closedir (man 3 closedir)
4. execve (man 2 execve)
5. exit (man 3 exit)
6. _exit (man 2 _exit)
7. fflush (man 3 fflush)
8. fork (man 2 fork)
9. free (man 3 free)
10. getcwd (man 3 getcwd)
11. getline (man 3 getline)
12. getpid (man 2 getpid)
13. isatty (man 3 isatty)
14. kill (man 2 kill)
15. malloc (man 3 malloc)
16. open (man 2 open)
17. opendir (man 3 opendir)
18. perror (man 3 perror)
19. read (man 2 read)
20. readdir (man 3 readdir)
21. signal (man 2 signal)
22. stat (__xstat) (man 2 stat)
23. lstat (__lxstat) (man 2 lstat)
24. fstat (__fxstat) (man 2 fstat)
25. strtok (man 3 strtok)
26. wait (man 2 wait)
27. waitpid (man 2 waitpid)
28. wait3 (man 2 wait3)
29. wait4 (man 2 wait4)
30. write (man 2 write)

# Compilation
Your shell will be compiled this way:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

## Testing
Your shell should work like this in interactive mode:

$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$


But also in non-interactive mode:

$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$

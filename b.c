#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/ucontext.h>
#include <sys/user.h>

void test()
{
    asm("int3");
}

void handler(int sig, siginfo_t *info, void *ucontext)
{
    ucontext_t *context = (ucontext_t *) ucontext;
    struct user_regs_struct *regs = (void *) context->uc_mcontext.gregs[REG_RIP];
    regs->rip = (long) test;
}

int main()
{
    struct sigaction sig;
    sig.sa_sigaction = handler;
    sig.sa_flags = SA_SIGINFO | SA_RESTART; 

    sigaction(SIGALRM, &sig, NULL);

    alarm(3);

    while (1) {
        printf("waiting...\n");
        sleep(1);
    }
}

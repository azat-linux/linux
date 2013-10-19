
#include <linux/printk.h>


/* Forward declarations */
struct task_struct;
struct linux_binprm;
struct cred;


inline static void cap_debug_cap(const struct cred *cred)
{
	printk(KERN_CRIT " cred_ptr: %p, cap_perm: %x:%x, cap_eff: %x:%x\n",
		cred,
		cred->cap_permitted.cap[0],
		cred->cap_permitted.cap[1],
		cred->cap_effective.cap[0],
		cred->cap_effective.cap[1]
	);
}

inline static void cap_debug_task(struct task_struct *task, const char *postfix)
{
	printk(KERN_CRIT "[cap] %s(%s) task: %p", postfix, task->comm, task);
	cap_debug_cap(task->cred);
	cap_debug_cap(task->real_cred);
}

inline static void cap_debug_binprm(struct linux_binprm *bprm, const struct cred *cred, const char *postfix)
{
	printk(KERN_CRIT "[cap] %s(%s) bprm_ptr: %p", postfix, bprm->filename, bprm);
        cap_debug_cap(cred);
}

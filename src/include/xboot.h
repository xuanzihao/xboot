#ifndef __XBOOT_H__
#define __XBOOT_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <configs.h>
#include <types.h>
#include <sizes.h>
#include <endian.h>
#include <byteorder.h>
#include <limits.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <ctype.h>
#include <errno.h>
#include <environ.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <locale.h>
#include <time.h>
#include <exit.h>
#include <io.h>
#include <ssize.h>
#include <malloc.h>
#include <charset.h>
#include <readline.h>
#include <version.h>
#include <runtime.h>
#include <xboot/list.h>
#include <xboot/initcall.h>
#include <xboot/kobj.h>
#include <xboot/proc.h>
#include <xboot/resource.h>
#include <xboot/logger.h>
#include <xboot/clk.h>
#include <xboot/irq.h>
#include <xboot/gpio.h>
#include <xboot/machine.h>
#include <xboot/bus.h>
#include <xboot/device.h>
#include <xboot/module.h>
#include <xboot/event.h>
#include <xboot/printk.h>
#include <time/tick.h>
#include <time/timer.h>
#include <time/delay.h>
#include <fs/fileio.h>

#if !defined(__ARCH__)
#define __ARCH__									""
#endif

#if !defined(__MACH__)
#define __MACH__									""
#endif

#if !defined(CONFIG_HEAP_SIZE)
#define	CONFIG_HEAP_SIZE							(SZ_8M)
#endif

#if !defined(CONFIG_NO_LOG)
#define	CONFIG_NO_LOG								(0)
#endif

#if !defined(CONFIG_EVENT_FIFO_LENGTH)
#define	CONFIG_EVENT_FIFO_LENGTH					(256)
#endif

#if !defined(CONFIG_MAX_NUMBER_OF_VFS_BIO)
#define	CONFIG_MAX_NUMBER_OF_VFS_BIO				(SZ_4K)
#endif

#if !defined(CONFIG_CMDLINE_LENGTH)
#define	CONFIG_CMDLINE_LENGTH						(SZ_4K)
#endif

#if !defined(CONFIG_VARNAME_LENGTH)
#define	CONFIG_VARNAME_LENGTH						(256)
#endif

#if !defined(CONFIG_COMMAND_HELP)
#define	CONFIG_COMMAND_HELP							(1)
#endif

#if !defined(CONFIG_COMMAND_ECHO)
#define	CONFIG_COMMAND_ECHO							(1)
#endif

#if !defined(CONFIG_COMMAND_ENV)
#define	CONFIG_COMMAND_ENV							(1)
#endif

#if !defined(CONFIG_COMMAND_EXEC)
#define	CONFIG_COMMAND_EXEC							(1)
#endif

#if !defined(CONFIG_COMMAND_HISTORY)
#define	CONFIG_COMMAND_HISTORY						(1)
#endif

#if !defined(CONFIG_COMMAND_VERSION)
#define	CONFIG_COMMAND_VERSION						(1)
#endif

#if !defined(CONFIG_COMMAND_CLEAR)
#define	CONFIG_COMMAND_CLEAR						(1)
#endif

#if !defined(CONFIG_COMMAND_PROBE)
#define	CONFIG_COMMAND_PROBE						(1)
#endif

#if !defined(CONFIG_COMMAND_EXIT)
#define	CONFIG_COMMAND_EXIT							(1)
#endif

#if !defined(CONFIG_COMMAND_NAND)
#define	CONFIG_COMMAND_NAND							(1)
#endif

#if !defined(CONFIG_COMMAND_SLEEP)
#define	CONFIG_COMMAND_SLEEP						(1)
#endif

#if !defined(CONFIG_COMMAND_SYNC)
#define	CONFIG_COMMAND_SYNC							(1)
#endif

#if !defined(CONFIG_COMMAND_MEMTEST)
#define	CONFIG_COMMAND_MEMTEST						(1)
#endif

#if !defined(CONFIG_COMMAND_GO)
#define	CONFIG_COMMAND_GO							(1)
#endif

#if !defined(CONFIG_COMMAND_REBOOT)
#define	CONFIG_COMMAND_REBOOT						(1)
#endif

#if !defined(CONFIG_COMMAND_XMODEM)
#define	CONFIG_COMMAND_XMODEM						(1)
#endif

#if !defined(CONFIG_COMMAND_HALT)
#define	CONFIG_COMMAND_HALT							(1)
#endif

#if !defined(CONFIG_COMMAND_MC)
#define	CONFIG_COMMAND_MC							(1)
#endif

#if !defined(CONFIG_COMMAND_MD)
#define	CONFIG_COMMAND_MD							(1)
#endif

#if !defined(CONFIG_COMMAND_MW)
#define	CONFIG_COMMAND_MW							(1)
#endif

#if !defined(CONFIG_COMMAND_CKSUM)
#define	CONFIG_COMMAND_CKSUM						(1)
#endif

#if !defined(CONFIG_COMMAND_LOAD)
#define	CONFIG_COMMAND_LOAD							(1)
#endif

#if !defined(CONFIG_COMMAND_MOUNT)
#define	CONFIG_COMMAND_MOUNT						(1)
#endif

#if !defined(CONFIG_COMMAND_UMOUNT)
#define	CONFIG_COMMAND_UMOUNT						(1)
#endif

#if !defined(CONFIG_COMMAND_LS)
#define	CONFIG_COMMAND_LS							(1)
#endif

#if !defined(CONFIG_COMMAND_MKDIR)
#define	CONFIG_COMMAND_MKDIR						(1)
#endif

#if !defined(CONFIG_COMMAND_CD)
#define	CONFIG_COMMAND_CD							(1)
#endif

#if !defined(CONFIG_COMMAND_PWD)
#define	CONFIG_COMMAND_PWD							(1)
#endif

#if !defined(CONFIG_COMMAND_RMDIR)
#define	CONFIG_COMMAND_RMDIR						(1)
#endif

#if !defined(CONFIG_COMMAND_RM)
#define	CONFIG_COMMAND_RM							(1)
#endif

#if !defined(CONFIG_COMMAND_MV)
#define	CONFIG_COMMAND_MV							(1)
#endif

#if !defined(CONFIG_COMMAND_FILERAM)
#define	CONFIG_COMMAND_FILERAM						(1)
#endif

#if !defined(CONFIG_COMMAND_CP)
#define	CONFIG_COMMAND_CP							(1)
#endif

#if !defined(CONFIG_COMMAND_CAT)
#define	CONFIG_COMMAND_CAT							(1)
#endif

#if !defined(CONFIG_COMMAND_CONSOLE)
#define	CONFIG_COMMAND_CONSOLE						(1)
#endif

#if !defined(CONFIG_COMMAND_LUA)
#define	CONFIG_COMMAND_LUA							(1)
#endif

#if !defined(CONFIG_COMMAND_LUAC)
#define	CONFIG_COMMAND_LUAC							(1)
#endif

#if !defined(CONFIG_COMMAND_TEST)
#define	CONFIG_COMMAND_TEST							(1)
#endif

#if !defined(CONFIG_COMMAND_BOOTLINUX)
#define	CONFIG_COMMAND_BOOTLINUX					(1)
#endif

#if !defined(CONFIG_COMMAND_CPUINFO)
#define	CONFIG_COMMAND_CPUINFO						(1)
#endif

#if !defined(CONFIG_COMMAND_MMUINFO)
#define	CONFIG_COMMAND_MMUINFO						(1)
#endif

#ifdef __cplusplus
}
#endif

#endif /* __XBOOT_H__ */

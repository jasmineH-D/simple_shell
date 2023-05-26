#include "shell.h"

/**
 * _miex - exits shell
 * @info: structure containing potential argu
 *  Return: exits with the specified exit status if info.argv[0]!= "exit"
*/

int _miex(info_t *info)
{
int exetch;
if (info->argv[1])
{
exetch = _strtoint(info->argv[1]);
if (exetch == -1)
{

info->status = 2;
print_errorms(info, "Illegal number: ");
_eppu(info->argv[1]);
_epitch('\n');
return (1);
}
info->err_num = _strtoint(info->argv[1]);
return (-2);

}
info->err_num = -1;
return (-2);
}

/**
 * _micedd - changes the current directory of the process
 * @info: structure containing potential argu
 *  Return: 0
 */

int _micedd(info_t *info)
{
char *s, *der, bufes[1024];
int chdir_ret;
s = getcwd(bufes, 1024);
if (!s)
_puuss("TODO: >>getcwd failure emsg here<<\n");
if (!info->argv[1])
{
der = _geevv(info, "HOME=");
if (!der)
chdir_ret =
chdir((der = _geevv(info, "PWD=")) ? der : "/");
else
chdir_ret = chdir(der);

}
else if (_stcmm(info->argv[1], "-") == 0)
{
if (!_geevv(info, "OLDPWD="))
{
_puuss(s);
_puuchi('\n');
return (1);
}
_puuss(_geevv(info, "OLDPWD=")), _puuchi('\n');
chdir_ret =
chdir((der = _geevv(info, "OLDPWD=")) ? der : "/");
}
else
chdir_ret = chdir(info->argv[1]);
if (chdir_ret == -1)
{
print_errorms(info, "can't cd to ");
_eppu(info->argv[1]), _epitch('\n');
}
else
{
_initenva(info, "OLDPWD", _geevv(info, "PWD="));
_initenva(info, "PWD", getcwd(bufes, 1024));
}
return (0);
}

/**
 * _mihely - changes the current directory of the process
 * @info: structure containing potential argu
 *  Return: 0
 */

int _mihely(info_t *info)
{
char **arg_array;
arg_array = info->argv;
_puuss("help call works. Function not yet implemented \n");
if (0)
_puuss(*arg_array);
return (0);
}


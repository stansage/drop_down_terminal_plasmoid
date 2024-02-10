# drop_down_terminal_plasmoid
Drop Down Terminal Plasmoid
# Simple colored bash prompt

Defined in `/etc/profile.d/bash-color-prompt.sh`

The prompt color theme can be customized simply by setting
the `PROMPT_COLOR` envvar, and optionally `PROMPT_DIR_COLOR`.

For example `PROMPT_COLOR='2;7'` is dim inverse-video
or `PROMPT_COLOR='44'` gives a blue background.

`PROMPT_DIR_COLOR` similarly changes the color of the working directory,
which otherwise defaults to `PROMPT_COLOR`.

## Coloring Examples

```shell
PROMPT_COLOR=0 # disable colors/attribs
PROMPT_COLOR=1 # bold prompt
PROMPT_COLOR=2 # dim prompt
PROMPT_COLOR=4 # underline prompt
PROMPT_COLOR='2;7' # dim reverse video
PROMPT_COLOR='42' # green background
PROMPT_COLOR='53' # overline separator
PROMPT_COLOR='1;33;44' # bold yellow on blue
PROMPT_COLOR='43;30' # black on yellow
PROMPT_COLOR='1;32' # bold green
PROMPT_COLOR='' # unset defaults to green
```

```shell
eval $(grep ANSI_COLOR /etc/os-release)
PROMPT_COLOR="$ANSI_COLOR"
```

See <https://en.wikipedia.org/wiki/ANSI_escape_code#SGR_(Select_Graphic_Rendition)_parameters> for ANSI codes details.

## Configurable variables
bash-color-prompt's PS1 has the following general structure:
`[PROMPT_START] PROMPT_USERHOST^PROMPT_SEPARATOR PROMPT_DIRECTORY^[PROMPT_END]`
(`^` means color reset) described below:

### `PROMPT_START` (optional)
Displayed at the start of the prompt.

### `PROMPT_USERHOST`
Default: `PROMPT_USERHOST='\u@\h'`

Defaults to `PROMPT_COLOR`.

See the PROMPTING section of `man bash` or `info bash` for
the available backslash-escaped special characters.

### `PROMPT_SEPARATOR`
Default: `PROMPT_SEPARATOR=':'`

eg you can change it to `'\n` or `' \t\n'

### `PROMPT_DIRECTORY`
Default: `PROMPT_DIRECTORY='\w'`

eg you can change it to `'\W'`

Defaults to `PROMPT_DIR_COLOR` if set or `PROMPT_COLOR`.

### `PROMPT_END`
Displayed at the end of the prompt (before `\$`).

## Traditional Red Hat prompt
```
PROMPT_START='['
PROMPT_END=']'
PROMPT_SEPARATOR=' '
PROMPT_DIRECTORY='\W'
PROMPT_COLOR='0'
```

## Defaults functions
The traditional Red Hat prompt can be set with the `prompt_traditional` function.

The prompt can be reset to default with the `prompt_default` function.

Use the `prompt_default_os` function to use `ANSI_COLOR` from `/etc/os-release`.

## Multiline prompt example
```
PROMPT_START='\t\n'
PROMPT_COLOR='30;43'
PROMPT_DIR_COLOR='44'
PROMPT_SEPARATOR='\n'
```
You can also set say `PS0='\t'` to timestamp the start of commands.

## Git branch integration
```
function prompt_command {
    ref=$(/usr/bin/git rev-parse --abbrev-ref HEAD 2> /dev/null)
    git_branch=${ref:+:$ref}
}
PROMPT_COMMAND=prompt_command
PROMPT_END='${git_branch@P}'
```

## Container support
Basic container support can be setup with say:
```
PROMPT_START='${container:+⬢ }'
```
though putting it in `PROMPT_USERHOST` might make more sense.

## Show exit code for error in red
```
PROMPT_END="${colorpre@P}31${colorsuf@P}'${?#0}'"%{colorreset}"
```

## Sourcing
Set `prompt_color_force`
(before sourcing `/etc/bashrc` or `bash-color-prompt.sh` directly)
to turn on bash-color-prompt unconditionally,
otherwise by default it is only setup cautiously
if `$TERM` ends in "color" *and* PS1 is the fedora or bash default.

For example:
```shellsession
if [ -t 0 ]; then
prompt_color_force=1
source /etc/profile.d/bash-color-prompt.sh
fi
```
can be added to `~/.bashrc` to turn on bash-color-prompt "everywhere".

## Contribute
Please open issues against
[shell-color-prompt](https://src.fedoraproject.org/rpms/shell-color-prompt).

shell-color is distributed under the GPL license version 2 or later.

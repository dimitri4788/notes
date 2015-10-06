###Homebrew cheatsheet

- If **--dry-run** or **-n** is passed, Homebrew will list all files which would be linked or which would be deleted by brew link --overwrite, but will not actually  link  or  delete any files.

Global Commands | Explanation
--- | ---
`$ brew update` | Update brew
`$ brew list` | Lists the installed libraries
`$ brew outdated` | What’s due for upgrades?

Commands | Explanation
--- | ---
`$ brew install boost` | Install a package
`$ brew upgrade boost` | Upgrade a package
`$ brew unlink boost` | Unlink
`$ brew link boost` | Link
`$ brew switch boost 1.56.0` | Change versions
`$ brew list --versions boost` | See what versions you have
`$ brew info git` | List versions, caveats, etc
`$ brew cleanup boost` | Remove old versions
`$ brew edit boost` | Edit this formula
`$ brew home boost` | Open homepage
`$ brew list boost --verbose` | To see where all of the files are located, use the list [formula] --verbose

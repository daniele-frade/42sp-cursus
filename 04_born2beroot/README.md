# Born2beRoot
<br>

>This project aims to introduce you to the wonderful world of virtualization. You will create your first machine in VirtualBox under specific instructions. Then, at the end of this project, you will be able to set up your own operating system while implementing strict rules.
<br>


## ✅ Mandatory part

This project consists of having you set up your first server by following specific rules:

- **OS**: you must choose as an operating system either the latest stable version of **Debian** or the latest stable version of **Rocky**.
- **LVM**: you must create at least 2 encrypted partitions using LVM. Below is an example of the expected partitioning:

  <img src="./images/Screenshot from 2023-10-10 16-57-08.png"/>

- **SSH**: a SSH service will be running on port `4242` only. For security reasons, connecting using SSH as root must not be possible.
- **UFW**: you have to configure your operating system with the UFW (or Firewalld for Rocky) firewall and thus leave only port `4242` open.
- **Hostname**: the hostname of your virtual machine must be your login ending with 42 (e.g., `will42`).
- **Password Policy**: you have to implement a strong password policy with the following requirements:
  - Your password has to expire every 30 days.
  - The minimum number of days allowed before the modification of a password will be set to 2.
  - The user has to receive a warning message 7 days before their password expires.
  - Your password must be at least 10 characters long. It must contain an uppercase letter, a lowercase letter, and a number. Also, it must not contain more than 3 consecutive identical characters.
  - The password must not include the name of the user.
  - The following rule does not apply to the root password: The password must have at least 7 characters that are not part of the former password.
  - Of course, your root password has to comply with this policy
- **Sudo**: you have to install and configure sudo following strict rules with the following requirements:
  - Authentication using sudo has to be limited to 3 attempts in case of an incorrect password.
  - A custom message of your choice has to be displayed if an error due to a wrong password occurs when using sudo.
  - Each action using sudo has to be archived, both inputs and outputs. The log file has to be saved in the `/var/log/sudo/sudo.log`.
  - The TTY mode has to be enabled for security reasons.
  - For security reasons too, the paths that can be used by sudo must be restricted like the example bellow:
    `/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin`
- **Users and Groups**: in addition to the `root user`, a `user with your login` as username has to be present. This user has to belong to the `user42` and `sudo` groups.
- **Script**: finally, you have to create a simple script called `monitoring.sh`. It must be developed in `bash`. At server startup, the script will display some information (listed below) on all terminals every 10 minutes:
  - The architecture of your operating system and its kernel version.
  - The number of physical processors.
  - The number of virtual processors.
  - The current available `RAM` on your server and its utilization rate as a percentage.
  - The current available memory on your server and its utilization rate as a percentage.
  - The current utilization rate of your processors as a percentage.
  - The date and time of the last reboot.
  - Whether `LVM` is active or not.
  - The number of active connections.
  - The number of users using the server.
  - The `IPv4` address of your server and its `MAC` (Media Access Control) address.
  - The number of commands executed with the sudo program.   
<br>

## ⭐ Bonus

You don’t have to do all the bonuses.

- Set up partitions correctly so you get a structure similar to the one below:

  <img src="./images/Screenshot from 2023-10-10 16-29-35.png"/>

- Set up a functional WordPress website with the following services: `Lighttpd`, `MariaDB`, and `PHP`.
- Set up a service of your choice that you think is useful (`NGINX` / `Apache2` excluded!).


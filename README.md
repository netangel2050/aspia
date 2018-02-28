Aspia
====================
Remote desktop and system information tool.

|Build Status|Coverity Scan Status|
|:--:|:--:|
|[![Build Status](https://ci.appveyor.com/api/projects/status/i7353lnxrgmi2omq/branch/master?svg=true)](https://ci.appveyor.com/project/dchapyshev/aspia/branch/master)|[![Coverity Scan Status](https://scan.coverity.com/projects/13117/badge.svg)](https://scan.coverity.com/projects/aspia-remote-desktop)|

Currently supported
-------------------
- Remote desktop management
- Remote desktop view
- Remote power management
- File transfer
- System information (for local and remote computers)
    + Hardware
        * DMI
        * Central Processor
        * Memory
        * Storage (logical drives, optical drives, ATA devices, SMART)
        * Display (video adapters, monitors)
        * Power Options
        * Printers
        * Windows Devices
    + Software
        * Applications
        * Updates
        * Services
        * Drivers
        * Processes
        * Licenses
    + Network
        * Network Cards
        * RAS Connections
        * Open Connections
        * Shared Resources
        * Open Files
        * Routes
    + Operating System
        * Operating System (version, architecture, uptime)
        * Task Scheduler
        * Users (users, user groups, active sessions)
        * Environment Variables
        * Event Logs
        * Windows Update
- Encryption (all transmitted information is encrypted using the algorithms XSalsa20 + Poly1305)
- Authorization (it is possible to add users with different access rights)
- Address book with encryption and master-password
- Work in service mode

It is planned to implement
--------------------------
- Audio transfer
- Authorization with Windows credentials
- NAT traversal

Building
--------
For building the project requires:
   - [Visual Studio 2017](http://visualstudio.com "Visual Studio 2017")
   - [YASM compiller](http://yasm.tortall.net/Download.html "YASM compiller") (version for "general use")

For more information, see BUILDING.md.

System requirements
-------------------
x86 or x86_64 CPU with SSE2 support, Windows 7/2008 R2 or higher.

Other information
-----------------
At the moment the project in development stage and is not intended for use.
If you have any questions, you can email me: dmitry@aspia.ru

Licensing
---------
Project code is available under the GNU Lesser General Public License 2.1.

For more information, see LICENSE.md.

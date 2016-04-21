===================================================
Library and Header files for the Visual C++ 7.0 Compiler
===================================================

In this zip file you will find a file called 'ode.lib' and a folder called 'ode'. Copy the ode.lib file to the lib folder of your compiler and copy the folder to the include folder of your compiler. I have only made one change to the config.h file which is located in the ode folder; this was due to a conflicting definition of int32 in winsock2.h.

The source code for ODE was released under the GNU Lesser General Public License http://www.opensource.org/licenses/lgpl-license.html or the BSD-style license http://opende.sourceforge.net/ode-license.html and you can download the complete source code and binaries for ODE at the official ode webite at http://www.q12.org. Thanks go to Russell Smith for developing ODE and open source project.
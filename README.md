# opencv-vs2019
A Simple Guide to Install and Configure OpenCV with Visual Studio (19)

1. Download OpenCV
   Go to OpenCV website: [https://opencv.org/releases/](https://opencv.org/releases/) and dowload the latest version or other old version you need.

2. Extract OpenCV
    Run the exe file that you downloaded, run to decompressed, extra to somewhere on your disk
    ![Decompressed](figs/extract_opencv.png)
    ![Result](figs/extract_opencv_02.png)

3. Create project and configuration <br>
   First, you need to create Empty Project (C++) in Visual Studio.
   ![](figs/figure_01.png)

   Create two folder: Dependencies and src in your project
   ![](figs/figure_02.png)
   
   Right click project -> Properties -> General. <br>
   For output directory: $(SolutionDir)bin\$(Platform)\$(Configuration)\ <br>
   For intermediate output directory: $(SolutionDir)bin\intermediates\$(Platform)\$(Configuration)\<br>
   For another option: C++ Langauge standard 14 or 17, etc

   ![](figs/figure_03.png)

   C/C++ tag configuration: <br>
   General -> Additional Include Directories: $(SolutionDir)Dependencies\OpenCV\include <br>
   ![](figs/figure_04.png)

   Linker tag configuration: <br>
   General -> Additional Libraries Directories: $(SolutionDir)Dependencies\OpenCV\x64\vc15\lib <br>
   ![](figs/figure_05.png)


   Input -> Additional Dependencies: opencv_world450.lib;opencv_world450d.lib;%(AdditionalDependencies) <br>
    These lib file depen on what version of OpenCV you use for your project, just look up in vc15\lib 
    ![](figs/figure_06.png)

    Finally, run test program, and copy .dll file to Debug or Release folder
    ![](figs/figure_07.png)

4. Run test simple opencv project

![](figs/program.png)

![](figs/program_1.png)

5. Good luck! :D

# 课程笔记：数字图像处理 (Digital Image Processing)

## 1. 课程基本信息
* **授课教师**：宋明黎 (Mingli Song)
* **助教**：苑瀚洋 博士、邱浩宇 博士
* **编程语言**：<font color="red">C / C++</font>
* **教学安排**：
    * 理论课：2 课时/周 × 16 周
    * 实验课：2 课时/双周 × 8 次（可自主完成）

## 2. 成绩评定 (Evaluation)
* **期末考试 (Exam)**：<font color="red">60%</font> (闭卷)
* **平时作业 (Homework)**：<font color="red">40%</font>
* **注意**：抄袭 (Plagiarism) 将导致 <font color="red">0 分</font>。

## 3. 核心知识点
* **重要性**：人类超过 <font color="red">60%</font> 的信息是通过视觉获取的。
* **主要应用方向**：
    * 图像采集（白平衡、全景拼接）
    * 显示与打印（插值算法）
    * 存储与传输（JPEG 压缩、数字水印）
    * 增强与修复（去噪、超分辨s率、修补）
    * 识别与理解（人脸检测、多模态大模型 LMM）



## 4. 教学大纲 (Chapter Outline)
1.  **Ch 1**：基本概念与位图 (BMP) 编程入门
2.  **Ch 2**：二值图像与形态学（<font color="red">腐蚀、膨胀、开/闭运算、击中击不中变换</font>）
3.  **Ch 3-4**：图像基本操作（灰度变换、<font color="red">直方图均衡化</font>、几何变换、插值）
4.  **Ch 5**：图像变形 (Morphing)
5.  **Ch 6-7**：卷积与滤波（<font color="red">平滑、锐化、双边滤波、引导滤波</font>）
6.  **Ch 8**：傅里叶变换（<font color="red">DFT、FFT、2D 傅里叶变换</font>）
7.  **Ch 9**：图像特征（SIFT、SURF、Transformer、扩散模型、LMM）



## 5. 第一次作业 (Assignment-1)
1.  读取彩色 BMP 图像。
2.  进行 **RGB -> YUV** 空间转换。
3.  提取 **Y 分量** 实现彩色转灰度。
4.  将灰度强度重排至 [0, 255]。
5.  写回彩色 BMP 文件。


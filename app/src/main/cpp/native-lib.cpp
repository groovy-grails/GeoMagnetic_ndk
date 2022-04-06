#include <jni.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>

extern "C"{
#include "GeomagnetismHeader.h"
#include "EGM9615.h"
}

std::string DoubleToString(const double value, unsigned int precision);
jstring charTojstring(JNIEnv* env, const char* pat);
char* jstringToChar(JNIEnv* env, jstring jstr);

extern "C" JNIEXPORT jstring JNICALL
Java_com_skydroid_hgcs_ndk001_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */,
        jstring jstr,
        jstring jstr1) {
    std::string hello = "Hello from C++";
    //return env->NewStringUTF(hello.c_str());

    char *a = jstringToChar(env, jstr);
    char *b = jstringToChar(env, jstr1);
    char *c = new char[strlen(a)+strlen(b)+1];
    strcpy(c,a);
    strcat(c,b);

    return (env)->NewStringUTF(c);
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_skydroid_hgcs_ndk001_MainActivity_resultFromJNI(
        JNIEnv* env,
        jobject /* this */,
        jstring jstr,
        jstring jstr1) {
    std::string hello = "Hello from C++";
    //return env->NewStringUTF(hello.c_str());

    char *a = jstringToChar(env, jstr);
    return (env)->NewStringUTF(a);
}

extern "C" JNIEXPORT jdouble JNICALL
Java_com_skydroid_hgcs_ndk001_MainActivity_declFromJNI(JNIEnv *env, jobject thiz, jint year,
                                                       jint month, jint day, jdouble doubleyear,
                                                       jdouble height, jdouble lat, jdouble lng) {
    // TODO: implement declFromJNI()

    double gnm[]={0.0,-29404.5,-1450.7,-2500.0,2982.0,1676.8,1363.9,-2381.0,1236.2,525.7,903.1,809.4,86.2,-309.4,47.9,-234.4,363.1,187.8,-140.7,-151.2,13.7,65.9,65.6,73.0,-121.5,-36.2,13.5,-64.7,80.6,-76.8,-8.3,56.5,15.8,6.4,-7.2,9.8,23.6,9.8,-17.5,-0.4,-21.1,15.3,13.7,-16.5,-0.3,5.0,8.2,2.9,-1.4,-1.1,-13.3,1.1,8.9,-9.3,-11.9,-1.9,-6.2,-0.1,1.7,-0.9,0.6,-0.9,1.9,1.4,-2.4,-3.9,3.0,-1.4,-2.5,2.4,-0.9,0.3,-0.7,-0.1,1.4,-0.6,0.2,3.1,-2.0,-0.1,0.5,1.3,-1.2,0.7,0.3,0.5,-0.2,-0.5,0.1,-1.1,-0.3};
    double hnm[]={0.0,0.0,4652.9,0.0,-2991.6,-734.8,0.0,-82.2,241.8,-542.9,0.0,282.0,-158.4,199.8,-350.1,0.0,47.7,208.4,-121.3,32.2,99.1,0.0,-19.1,25.0,52.7,-64.4,9.0,68.1,0.0,-51.4,-16.8,2.3,23.5,-2.2,-27.2,-1.9,0.0,8.4,-15.3,12.8,-11.8,14.9,3.6,-6.9,2.8,0.0,-23.3,11.1,9.8,-5.1,-6.2,7.8,0.4,-1.5,9.7,0.0,3.4,-0.2,3.5,4.8,-8.6,-0.1,-4.2,-3.4,-0.1,-8.8,0.0,-0.0,2.6,-0.5,-0.4,0.6,-0.2,-1.7,-1.6,-3.0,-2.0,-2.6,0.0,-1.2,0.5,1.3,-1.8,0.1,0.7,-0.1,0.6,0.2,-0.9,-0.0,0.5};
    double dgnm[]={0.0,6.7,7.7,-11.5,-7.1,-2.2,2.8,-6.2,3.4,-12.2,-1.1,-1.6,-6.0,5.4,-5.5,-0.3,0.6,-0.7,0.1,1.2,1.0,-0.6,-0.4,0.5,1.4,-1.4,-0.0,0.8,-0.1,-0.3,-0.1,0.7,0.2,-0.5,-0.8,1.0,-0.1,0.1,-0.1,0.5,-0.1,0.4,0.5,0.0,0.4,-0.1,-0.2,-0.0,0.4,-0.3,-0.0,0.3,-0.0,-0.0,-0.4,0.0,-0.0,-0.0,0.2,-0.1,-0.2,-0.0,-0.1,-0.2,-0.1,-0.0,-0.0,-0.1,-0.0,0.0,-0.0,-0.1,0.0,-0.0,-0.1,-0.1,-0.1,-0.1,0.0,-0.0,-0.0,0.0,-0.0,-0.0,0.0,-0.0,0.0,-0.0,-0.0,-0.0,-0.1};
    double dhnm[]={0.0,0.0,-25.1,0.0,-30.2,-23.9,0.0,5.7,-1.0,1.1,0.0,0.2,6.9,3.7,-5.6,0.0,0.1,2.5,-0.9,3.0,0.5,0.0,0.1,-1.8,-1.4,0.9,0.1,1.0,0.0,0.5,0.6,-0.7,-0.2,-1.2,0.2,0.3,0.0,-0.3,0.7,-0.2,0.5,-0.3,-0.5,0.4,0.1,0.0,-0.3,0.2,-0.4,0.4,0.1,-0.0,-0.2,0.5,0.2,0.0,-0.0,0.1,-0.3,0.1,-0.2,0.1,-0.0,-0.1,0.2,-0.0,0.0,-0.0,0.1,0.0,0.2,-0.0,0.0,0.1,-0.0,-0.1,0.0,-0.0,0.0,-0.0,0.0,-0.1,0.1,-0.0,0.0,-0.0,0.1,-0.0,-0.0,0.0,-0.1};

    MAGtype_MagneticModel *MagneticModels, *TimedMagneticModel;

    int num_terms = CALCULATE_NUMTERMS(12);
    int NumTerms = ((12 + 1) * (12 + 2) / 2);
    MagneticModels = MAG_AllocateModelMemory(num_terms);
    TimedMagneticModel = MAG_AllocateModelMemory(NumTerms);

    MagneticModels->EditionDate = 0;
    MagneticModels->epoch = 2020.0;
    //MagneticModels->ModelName = "WMM-2020";
    strcpy(MagneticModels->ModelName,"WMM-2020");
    MagneticModels->nMax = 12;
    MagneticModels->nMaxSecVar = 12;
    MagneticModels->SecularVariationUsed = 0;
    MagneticModels->CoefficientFileEndDate = 2025.0;
    MagneticModels->Main_Field_Coeff_G = gnm;
    //printf("%f  ", *(MagneticModels->Main_Field_Coeff_G + 2));
    MagneticModels->Secular_Var_Coeff_G = dgnm;
    MagneticModels->Main_Field_Coeff_H = hnm;
    MagneticModels->Secular_Var_Coeff_H = dhnm;

    MAGtype_Ellipsoid Ellip;
    MAGtype_CoordSpherical CoordSpherical;
    MAGtype_CoordGeodetic CoordGeodetic;
    MAGtype_Date UserDate;
    MAGtype_Geoid Geoid;

    MAGtype_GeoMagneticElements GeoMagneticElements, Errors;


    MAG_SetDefaults(&Ellip, &Geoid); /* Set default values and constants */
    /* Set EGM96 Geoid parameters */
    Geoid.GeoidHeightBuffer = GeoidHeightBuffer;
    Geoid.Geoid_Initialized = 1;
    /* Set EGM96 Geoid parameters end */

    /*input params*/
    CoordGeodetic.phi = lat;
    CoordGeodetic.lambda = lng;
    Geoid.UseGeoid = 0;
    CoordGeodetic.HeightAboveEllipsoid = height;
    CoordGeodetic.HeightAboveGeoid = CoordGeodetic.HeightAboveEllipsoid;
    UserDate.Year=year;
    UserDate.Month=month;
    UserDate.Day=day;
    UserDate.DecimalYear=doubleyear;
    /*input params end*/

    /* here init UserDate*/

    MAG_GeodeticToSpherical(Ellip, CoordGeodetic, &CoordSpherical); /*Convert from geodetic to Spherical Equations: 17-18, WMM Technical report*/
    MAG_TimelyModifyMagneticModel(UserDate, MagneticModels, TimedMagneticModel); /* Time adjust the coefficients, Equation 19, WMM Technical report */
    MAG_Geomag(Ellip, CoordSpherical, CoordGeodetic, TimedMagneticModel, &GeoMagneticElements); /* Computes the geoMagnetic field elements and their time change*/
    MAG_CalculateGridVariation(CoordGeodetic, &GeoMagneticElements);
    MAG_WMMErrorCalc(GeoMagneticElements.H, &Errors);
    MAG_PrintUserDataWithUncertainty(GeoMagneticElements, Errors, CoordGeodetic, UserDate, TimedMagneticModel, &Geoid); /* Print the results */

    //return (env)->NewStringUTF(DoubleToString(GeoMagneticElements.Decl,6).c_str());
    return GeoMagneticElements.Decl;
    //return DoubleToString(GeoMagneticElements.Decl,2);
    //return (env)->NewStringUTF(a);
}


std::string DoubleToString(const double value, unsigned int precision)
{
   std::ostringstream out;
   if (precision > 0)
       out.precision(precision);

   out << value;
   return out.str();
}

jstring charTojstring(JNIEnv* env, const char* pat) {
    //定义java String类 strClass
    jclass strClass = (env)->FindClass("Ljava/lang/String;");
    //获取String(byte[],String)的构造器,用于将本地byte[]数组转换为一个新String
    jmethodID ctorID = (env)->GetMethodID(strClass, "<init>", "([BLjava/lang/String;)V");
    //建立byte数组
    jbyteArray bytes = (env)->NewByteArray(strlen(pat));
    //将char* 转换为byte数组
    (env)->SetByteArrayRegion(bytes, 0, strlen(pat), (jbyte*) pat);
    // 设置String, 保存语言类型,用于byte数组转换至String时的参数
    jstring encoding = (env)->NewStringUTF("UTF8");
    //将byte数组转换为java String,并输出
    return (jstring) (env)->NewObject(strClass, ctorID, bytes, encoding);
}

char* jstringToChar(JNIEnv* env, jstring jstr) {
    char* rtn = NULL;
    jclass clsstring = env->FindClass("java/lang/String");
    jstring strencode = env->NewStringUTF("UTF8");
    jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray) env->CallObjectMethod(jstr, mid, strencode);
    jsize alen = env->GetArrayLength(barr);
    jbyte* ba = env->GetByteArrayElements(barr, JNI_FALSE);
    if (alen > 0) {
        rtn = (char*) malloc(alen + 1);
        memcpy(rtn, ba, alen);
        rtn[alen] = 0;
    }
    env->ReleaseByteArrayElements(barr, ba, 0);
    return rtn;
}

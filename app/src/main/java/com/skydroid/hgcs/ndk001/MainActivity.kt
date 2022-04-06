package com.skydroid.hgcs.ndk001

import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import kotlinx.android.synthetic.main.activity_main.*
import java.util.*

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // Example of a call to a native method
        //sample_text.text = stringFromJNI("0000","111")
        //sample_text.text = resultFromJNI("0000","1111")
        val date = Calendar.getInstance()
        val year = date.get(Calendar.YEAR)
        val month = date.get(Calendar.MONTH)+1
        val day = date.get(Calendar.DAY_OF_MONTH)
        var r=""
        r+=year.toString()+","+month+","+day+","+makedoubleyear()+","+declFromJNI(year,month,day,makedoubleyear(),0.0,39.0,116.0).toString()
        sample_text.text = r
    }

    fun makedoubleyear():Double{
        val date = Calendar.getInstance()
        val year = date.get(Calendar.YEAR)
        val days = date.get(Calendar.DAY_OF_YEAR)
        var yeardays=365.0
        if(isleapyear()){
            yeardays=366.0
        }
        return year+days/yeardays
    }

    fun isleapyear():Boolean{
        val date = Calendar.getInstance()
        date.set(Calendar.DECEMBER,31)
        if(date.get(Calendar.DAY_OF_YEAR)==366){
            return true
        }else{
            return false
        }
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(str:String,str1:String): String
    external fun resultFromJNI(str:String,str1:String): String
    external fun declFromJNI(year:Int,month:Int,day:Int,doubleyear:Double,height:Double,lat:Double,lng:Double): Double

    companion object {

        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("native-lib")
        }
    }
}

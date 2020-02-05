package com.seven.lib.androidhook

import android.os.Build
import android.util.Log

object AndroidHook {
    private var hiddenAPIAccessible = false


    private val isPie: Boolean
        get() = Build.VERSION.SDK_INT > 27 || Build.VERSION.SDK_INT == 27 && Build.VERSION.PREVIEW_SDK_INT > 0


    fun hookPieHiddenAPI(mode: Mode) {
        if (hiddenAPIAccessible) {
            return
        }

        if (mode == AndroidHook.Mode.MODE_64_BIT) {
            System.loadLibrary("androidhook_64")
        } else {
            System.loadLibrary("androidhook")
        }

        if (isPie) {
            try {
                accessPieHiddenAPI()
            } catch (e: Throwable) {
                e.printStackTrace()
                Log.e("AndroidHook", "Could not set hidden api accessible", e)
            }

        }
        hiddenAPIAccessible = true
    }

    private external fun accessPieHiddenAPI()

    enum class Mode {
        MODE_32_BIT, MODE_64_BIT
    }
}
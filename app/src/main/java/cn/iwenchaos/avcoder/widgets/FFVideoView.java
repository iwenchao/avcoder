package cn.iwenchaos.avcoder.widgets;

import android.content.Context;
import android.graphics.PixelFormat;
import android.util.AttributeSet;
import android.view.Surface;
import android.view.SurfaceView;

import cn.iwenchaos.avcoder.utils.FFUtil;

/**
 * Created by chaos
 * on 2019/7/13. 10:35
 * 文件描述：
 */
public class FFVideoView extends SurfaceView {


    private Surface mSurface;


    public FFVideoView(Context context) {
        this(context, null);
    }

    public FFVideoView(Context context, AttributeSet attrs) {
        this(context, attrs, -1);
    }

    public FFVideoView(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        init();
    }


    private void init() {
        getHolder().setFormat(PixelFormat.RGBA_8888);
        mSurface = getHolder().getSurface();
    }


    public void playVideo(final String filePath){
        new Thread(new Runnable() {
            @Override
            public void run() {
                FFUtil.playVideo(filePath);
            }
        }).start();
    }



}

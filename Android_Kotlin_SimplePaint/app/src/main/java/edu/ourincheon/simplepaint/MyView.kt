package edu.ourincheon.simplepaint

import android.content.Context
import android.graphics.*
import android.util.AttributeSet
import android.view.MotionEvent
import android.view.View

class MyView : View {

    private var mColor: Int = 0
    private val mPaint: Paint = Paint()
    lateinit var myBitmap: Bitmap
    lateinit var myCanvas: Canvas
    var mPath: Path = Path()

    constructor(context: Context) : super(context) {
        initialize(null)
    }
    constructor(context: Context, attributeSet: AttributeSet) : super(context, attributeSet) {
        initialize(attributeSet)
    }
    constructor(context: Context, attributeSet: AttributeSet, defStyleAttributeSet: Int) : super(context, attributeSet, defStyleAttributeSet) {
        initialize(attributeSet)
    }

    private fun initialize(attributeSet: AttributeSet?) {
        if (attributeSet == null) return

        val ta = context.obtainStyledAttributes(attributeSet, R.styleable.MyCustomView)
        mColor = ta.getColor(R.styleable.MyCustomView_selected_color, Color.WHITE)
        mPaint.color = mColor
        mPaint.strokeWidth = 10f
        mPaint.style = Paint.Style.STROKE
        mPaint.strokeJoin = Paint.Join.ROUND
        ta.recycle()
    }

    override fun onSizeChanged(w: Int, h: Int, oldw: Int, oldh: Int) {
        super.onSizeChanged(w, h, oldw, oldh)
        myBitmap = Bitmap.createBitmap(w, h, Bitmap.Config.ARGB_8888)
        myCanvas = Canvas(myBitmap)
    }
    override fun onDraw(canvas: Canvas?) {
        val paint = Paint()
        super.onDraw(canvas)
        canvas?.drawBitmap(myBitmap, 0f, 0f, paint)
        canvas?.drawPath(mPath, mPaint)
    }

    override fun onTouchEvent(event: MotionEvent?): Boolean {
        if (event == null) return super.onTouchEvent(event)
        val x = event.x
        val y = event.y
        when (event.action) {
            MotionEvent.ACTION_DOWN -> mPath.moveTo(x, y)
            MotionEvent.ACTION_MOVE -> mPath.lineTo(x, y)
            MotionEvent.ACTION_UP -> {
                myCanvas?.drawPath(mPath, mPaint)
                mPath.reset()
            }
            else -> return super.onTouchEvent(event)
        }
        invalidate()
        return true
    }
    fun changeColor(color: String) {
        mPaint.color = Color.parseColor(color)
    }
}
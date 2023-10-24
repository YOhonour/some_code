import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class MinuteKLineCalculator {
    public static void main(String[] args) {
        // 创建一个映射以存储每个分钟窗口的数据
        Map<Integer, MinuteData> minuteDataMap = new HashMap<>();

        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts.length >= 10) {
                    String dataTimestampStr = parts[3];
                    int dataTimestamp = Integer.parseInt(dataTimestampStr);
                    int minute = (dataTimestamp / 1000000 % 100) * 60 + (dataTimestamp / 10000 % 100);

                    // 只处理交易时间段 [9:30,11:30][13:00,15:00]
                    if ((minute >= 930 && minute < 1130) || (minute >= 1300 && minute < 1500)) {
                        double lastPx = Double.parseDouble(parts[8]);
                        int businessCount = Integer.parseInt(parts[9]);
                        long businessAmount = Long.parseLong(parts[10]);
                        double businessBalance = Double.parseDouble(parts[11]);

                        // 如果该分钟窗口尚不存在于映射中，则创建一个新的 MinuteData 对象
                        minuteDataMap.computeIfAbsent(minute, k -> new MinuteData());

                        // 更新该分钟窗口的数据
                        MinuteData minuteData = minuteDataMap.get(minute);
                        if (minuteData.getOpenPx() == null) {
                            minuteData.setOpenPx(lastPx);
                        }
                        minuteData.setHighPx(Math.max(minuteData.getHighPx(), lastPx));
                        minuteData.setLowPx(Math.min(minuteData.getLowPx(), lastPx));
                        minuteData.setClosePx(lastPx);
                        minuteData.setBusinessCount(minuteData.getBusinessCount() + businessCount);
                        minuteData.setBusinessAmount(minuteData.getBusinessAmount() + businessAmount);
                        minuteData.setBusinessBalance(minuteData.getBusinessBalance() + businessBalance);
                    }
                }
            }

            // 打印结果
            System.out.println("data_timestamp,open_px,high_px,low_px,close_px,business_count,business_amount,business_balance");
            for (Map.Entry<Integer, MinuteData> entry : minuteDataMap.entrySet()) {
                int minute = entry.getKey();
                MinuteData minuteData = entry.getValue();
                System.out.printf("%06d,%.2f,%.2f,%.2f,%.2f,%d,%d,%.2f%n",
                        minute, minuteData.getOpenPx(), minuteData.getHighPx(),
                        minuteData.getLowPx(), minuteData.getClosePx(),
                        minuteData.getBusinessCount(), minuteData.getBusinessAmount(),
                        minuteData.getBusinessBalance());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

class MinuteData {
    private Double openPx;
    private Double highPx;
    private Double lowPx;
    private Double closePx;
    private int businessCount;
    private long businessAmount;
    private double businessBalance;

    public Double getOpenPx() {
        return openPx;
    }

    public void setOpenPx(Double openPx) {
        this.openPx = openPx;
    }

    public Double getHighPx() {
        return highPx;
    }

    public void setHighPx(Double highPx) {
        this.highPx = highPx;
    }

    public Double getLowPx() {
        return lowPx;
    }

    public void setLowPx(Double lowPx) {
        this.lowPx = lowPx;
    }

    public Double getClosePx() {
        return closePx;
    }

    public void setClosePx(Double closePx) {
        this.closePx = closePx;
    }

    public int getBusinessCount() {
        return businessCount;
    }

    public void setBusinessCount(int businessCount) {
        this.businessCount = businessCount;
    }

    public long getBusinessAmount() {
        return businessAmount;
    }

    public void setBusinessAmount(long businessAmount) {
        this.businessAmount = businessAmount;
    }

    public double getBusinessBalance() {
        return businessBalance;
    }

    public void setBusinessBalance(double businessBalance) {
        this.businessBalance = businessBalance;
    }
}

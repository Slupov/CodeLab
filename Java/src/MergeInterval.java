import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

/**
 * @author Stoyan Lupov
 * @date 09/04/2019
 * @url https://leetcode.com/problems/merge-intervals/
 **/
public class MergeInterval {
    private static class Interval {
        int start;
        int end;

        Interval() {
            start = 0;
            end = 0;
        }

        Interval(int s, int e) {
            start = s;
            end = e;
        }
    }

    public static void main(String[] args) {

        List<Interval> list = new ArrayList<>();

        list.add(new Interval(1,3));
        list.add(new Interval(2,6));
        list.add(new Interval(8,10));
        list.add(new Interval(15,18));

        merge(list);
    }


    public static List<Interval> merge(List<Interval> intervals) {
        final int INT_CNT = intervals.size();

        if (INT_CNT == 1 || INT_CNT == 0) {
            return intervals;
        }

        intervals.sort((p1, p2) -> {
            if (p1.start == p2.start) return 0;
            return (p1.start < p2.start) ? -1 : 1;
        });

        List<Interval> result = new ArrayList<>();

        Interval temp = new Interval(intervals.get(0).start, intervals.get(0).end);

        for (int i = 1; i < INT_CNT; i++) {
            //situation "temp's end is inside i-th interval"
            if (temp.end >= intervals.get(i).start && temp.end < intervals.get(i).end) {
                temp = new Interval(temp.start, intervals.get(i).end);
            }
            //situation "temp's end is after or the same as i-th end"
            else if (temp.end >= intervals.get(i).end) {
                temp = new Interval(temp.start, temp.end);
            }
            //situation "temp is already merged as best as it could"
            else {
                result.add(temp);
                temp = intervals.get(i);
            }
        }

        //add last one
        result.add(temp);
        return result;
    }
}

import java.math.BigInteger;

class Main {
    public static void main(String args[]) {
        BigInteger biFromString = new BigInteger("1234567890987654321"); // 1234567890987654321

        BigInteger biFromByteArray = new BigInteger(
                new byte[] { 64, 64, 64, 64, 64, 64 }); // 70644700037184

        BigInteger biFromSignMagnitude = new BigInteger(-1,
                new byte[] { 64, 64, 64, 64, 64, 64 }); // -70644700037184

        // add
        BigInteger bigInteger1 = new BigInteger("1234567890987654321");
        BigInteger bigInteger2 = new BigInteger("214145124124123112");
        BigInteger res = bigInteger1.add(bigInteger2);
        System.out.println(res); // 1448713015111777433

        // subtract
        BigInteger bigInteger1 = new BigInteger("1234567890987654321");
        BigInteger bigInteger2 = new BigInteger("214145124124123112");
        BigInteger res = bigInteger1.subtract(bigInteger2);
        System.out.println(res); // 1020422766863531209

        // Multiply
        BigInteger bigInteger1 = new BigInteger("1234567890987654321");
        BigInteger bigInteger2 = new BigInteger("214145124124123112");
        BigInteger res = bigInteger1.multiply(bigInteger2);
        System.out.println(res); // 264376694255208125644345211902766952

        // Divide
        BigInteger bigInteger1 = new BigInteger("1234567890987654321");
        BigInteger bigInteger2 = new BigInteger("214145124124123112");
        BigInteger res = bigInteger1.divide(bigInteger2);      
        System.out.println(res); // 5

        // Pow
        BigInteger bigInteger = new BigInteger("1234567890987654321");
        BigInteger pow = bigInteger.pow(2); // 1524157877457704723228166437789971041

        // Compare
        BigInteger bigInteger1 = new BigInteger("1234567890987654321");
        BigInteger bigInteger2 = new BigInteger("1234567890987654321");
        BigInteger bigInteger3 = new BigInteger("5121241241254123");
        System.out.println(bigInteger1.compareTo(bigInteger2)); // 0
        System.out.println(bigInteger1.compareTo(bigInteger3)); // 1
        System.out.println(bigInteger3.compareTo(bigInteger1)); // -1

    }
}


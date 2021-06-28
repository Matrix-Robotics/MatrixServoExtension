## Begin

Reset and initialize controller to default state.

```Arduino
bool begin()
```
### Return

- A **boolean** result of initialization. (`true` / `false`)
<br /><br /><br />
***
<br />

## Set Angle

RC-servo angle setting.

```Arduino
void setAngle(int ch, uint8_t Angle)
```

### Parameters

- `ch` is a channel number from `1` through `8`
- `Angle` is a servo angle from `0` through `180` (unit: degree)
<br /><br /><br />
***
<br />

## Channel Release

Release the select servo.

```Arduino
void ChannelRelease(int ch)
```

### Parameters

- `ch` is a channel number from `1` through `8`
<br /><br /><br />
***
<br />

## Get Battray Voltage

Get battray **voltage** of controller.

```Arduino
float getVbat()
```

### Return

- A **float** number from `0` through `8.4`. (unit: v)
